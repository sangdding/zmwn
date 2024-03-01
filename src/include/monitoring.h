#include "libzbd/zbd.h"

typedef struct ZoneStatus {
    __u64 zslba;
    __u64 wp;
} ZoneStatus;

// initialize monitoring structure
int init_monitoring();

// free shared memory
int free_monitoring();