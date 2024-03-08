#include <fcntl.h>
#include <libnvme.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "initializer.h"
#include "file.h"

ZoneDeviceInfo *zoneDeviceInfo;

int initalize_device(char* filename)
{
    int ret;
    zoneDeviceInfo = (ZoneDeviceInfo *)malloc(sizeof(ZoneDeviceInfo));
    zoneDeviceInfo->filename = filename;

    // check device is zone_block_device
    ret = zbd_device_is_zoned(filename);
    if (!ret) return 0;

    // device open
    ret = zbd_open(filename, O_RDWR, zoneDeviceInfo->device);
    if (!ret) return 0;
    zoneDeviceInfo->device_fd = ret;

    // init namespace_id
    ret = nvme_get_nsid(zoneDeviceInfo->device_fd, &(zoneDeviceInfo->namespace_id));
    if (ret) return 0;

    // init metadata area
    init_metadata();
    return 1;
}

int init_metadata()
{
    const unsigned int fd = 3;
    int ret;
    struct nvme_zns_append_args *args;
    char data[4096];
    memset(data, 0, sizeof(data));
    strcpy(data, "Hello, world!\n");
    args = (struct nvme_zns_append_args *)malloc(sizeof(struct nvme_zns_append_args));
    gen_append_args(args, 0, data, *zoneDeviceInfo);
    ret = nvme_zns_append(args);
    printf("%d\n", args->data_len);
    printf("%d\n", args->nlb);
    printf("%ld\n", (uint64_t)args->result);
    printf("%s\n", strerror(errno));
    if (ret) return 0;
    
    return 1;
}