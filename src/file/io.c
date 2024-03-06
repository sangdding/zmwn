#include "file.h"

struct nvme_zns_append_args* gen_append_args(__u64 zslba, void *data, ZoneDeviceInfo device)
{
    struct nvme_zns_append_args args;
    __u64 *result;
    
    args.zslba = zslba;
    args.result = result;
    args.data = data;
    args.args_size = sizeof(args);
    args.fd = device.device_fd;
    args.nsid = device.namespace_id;
    args.data_len = sizeof(*data);
    args.nlb = (args.data_len / BLOCK_SIZE) + 1;

    return &args;
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