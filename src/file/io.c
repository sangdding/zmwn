#include "file.h"
#include <string.h>

void gen_append_args(struct nvme_zns_append_args* args, __u64 zslba, void *data, ZoneDeviceInfo device)
{
    __u64 *result = NULL;
    size_t len = strlen(data);
    args->zslba = zslba;
    args->result = result;
    args->data = data;
    args->args_size = sizeof(*args);
    args->fd = device.device_fd;
    args->nsid = device.namespace_id;
    args->timeout = NVME_DEFAULT_IOCTL_TIMEOUT;
    args->data_len = len;
    args->nlb = len / BLOCK_SIZE;
}

int zopen(unsigned int fd, mode_t mode)
{
    // if (mode == O_CREAT)
    // {

    // }
    return 1;
}

int zread()
{
    return 1;

}

int zwrite()
{
    return 1;

}

int zdelete()
{
    return 1;
}