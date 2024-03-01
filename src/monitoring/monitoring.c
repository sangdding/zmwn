#include <monitoring.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int init_monitoring()
{

    int shm_id;
    int valid_zones;
    unsigned int *nr_zones;
    key_t key = 1234;
    ZoneStatus *zone_status;
    static const char *filename = "/dev/nvme0n2";
    struct zbd_info *info;
    struct zbd_zone *zones;

    // check device is zbd_device
    if (zbd_device_is_zoned(filename) == 0)
    {
        perror("ERROR ");
    }

    // open zdb_device
    if (zdb_open(filename, O_RDWR, info))
    {
        perror("ERROR ");
        exit(1);
    }

    // initialize zone status
    zone_status = (ZoneStatus *)malloc(info->max_nr_open_zones * sizeof(ZoneStatus));
    if (zone_status == NULL)
    {
        perror("zone status allocation failed");
        exit(1);
    }

    zones = (struct zbd_zone *)malloc(info->nr_zones * sizeof(struct zbd_zone));
    if (zdb_report_zones(filename, 0, 0, zbd_report_option(ZBD_RO_ALL), zones, nr_zones))
    {
        perror("report error");
        exit(1);
    }

    valid_zones = update_zone_state(zones, *nr_zones);
    for (int i = 0; i < info->max_nr_active_zones; i++)
    {
        if (valid_zones == 0)
        {
            perror("There is no more valid zones. Need to reset device.");
            exit(1);
        }
    }

    // create shared memory area
    shm_id = shmget(key, sizeof(ZoneStatus), IPC_CREAT | 0666);
    if (shm_id < 0)
    {
        perror("shmget");
        exit(1);
    }

    zone_status = (ZoneStatus *)shmat(shm_id, NULL, 0);
    if (zone_status == (ZoneStatus *)-1)
    {
        perror("shmat");
        exit(1);
    }
}

int update_zone_state(struct zbd_zone *zones, unsigned int nr_zones)
{
    int valid_zones = 0;

    for (int i = 0; i < nr_zones; i++)
    {
        if (zones[i].flags == ZBD_ZONE_COND_EMPTY ||
            zones[i].flags == ZBD_ZONE_COND_EXP_OPEN ||
            zones[i].flags == ZBD_ZONE_COND_IMP_OPEN) valid_zones++;
    }

    return valid_zones;
}