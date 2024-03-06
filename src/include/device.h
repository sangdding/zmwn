#include <libzbd/zbd.h>

typedef struct ZoneDeviceInfo
{
    struct zbd_info *device;
    int device_fd;
    __u32   namespace_id;
    const char* filename;
} ZoneDeviceInfo;