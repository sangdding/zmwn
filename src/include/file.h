#include <fcntl.h>
#include <libnvme.h>
#include <asm-generic/int-ll64.h>

#include "device.h"

#define BLOCK_SIZE 4096
#define MAX_FILENAME_LENGTH 256

/**
 * fnode - data structure of file metadata
 * @fnode_number: number of fnode
 * @file_type: 'f' for file, 'd' for directory
 * @permission: File permissions
 * @size: Size of the file in bytes
 * @lba_array: data lba of the file
*/
typedef struct fnode {
    unsigned int fnode_number;
    char file_type;
    mode_t permission;
    off_t size;
    unsigned int* lba_array;
} fnode;

/**
 * DirectoryEntry - data structure of directory mapping table
 * @filename: file name of directory
 * @fnode_number: index of fnode
*/
typedef struct DirectoryEntry {
    char fileName[MAX_FILENAME_LENGTH];
    unsigned int inodeNumber;
} DirectoryEntry;

/**
 * Directory - data structure of directory
 * @entries: entries of directory
 * @size: number of directory
 * @capacity: memory size for saving directory entries 
*/
typedef struct Directory {
    DirectoryEntry* entries;
    size_t size;
    size_t capacity;
} Directory;


void gen_append_args(struct nvme_zns_append_args*, __u64 zslba, void *data, ZoneDeviceInfo device);

int zopen();

int zread();

int zwrite();

int zdelete();