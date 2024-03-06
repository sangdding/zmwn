#include <fcntl.h>
#include <libnvme.h>
#include <asm-generic/int-ll64.h>

#include "device.h"

#define BLOCK_SIZE 4096

typedef struct fnode {
    mode_t mode;
    unsigned int fd;
    unsigned int* zslba_array;
    off_t size;
} fnode;

void gen_append_args(struct nvme_zns_append_args*, __u64 zslba, void *data, ZoneDeviceInfo device);

int zopen();

int zread();

int zwrite();

int zdelete();