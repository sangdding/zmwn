#include <fcntl.h>
#include <libnvme.h>

#include "initializer.h"
#include "file.h"

ZoneDeviceInfo *zoneDeviceInfo;

int initalize_device(char* filename)
{
    int ret;

    zoneDeviceInfo->filename = filename;

    // check device is zone_block_device
    ret = zbd_device_is_zoned(filename);
    if (ret) return 0;

    // device open
    ret = zbd_open(filename, O_RDWR, zoneDeviceInfo->device);
    if (ret) return 0;
    zoneDeviceInfo->device_fd = ret;

    // init namespace_id
    ret = nvme_get_nsid(zoneDeviceInfo->device_fd, &(zoneDeviceInfo->namespace_id));
    if (ret) return 0;

    // init metadata area
    return 1;
    
}

int init_metadata()
{
    const unsigned int fd = 3;
    int ret;
    struct nvme_zns_append_args args;
    char* data = "fnode";


    args = *gen_append_args(0, data, *zoneDeviceInfo);
    ret = nvme_zns_append(&args);

    if (ret) return 0;
    
    return 1;
}