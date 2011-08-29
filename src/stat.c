/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-29.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

int check_stat(char *filename) {
    struct stat sb;

    if (stat(filename, &sb) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    printf("File type:");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");        break;
        case S_IFCHR:  printf("character device\n");    break;
        case S_IFDIR:  printf("directory\n");           break;
        case S_IFIFO:  printf("FIFO/pipe\n");           break;
        case S_IFLNK:  printf("symlink\n");             break;
        case S_IFREG:  printf("regular file\n");        break;
        case S_IFSOCK: printf("socket\n");              break;
        default:       printf("unknown?\n");            break;
    }

    printf("I-node number: %ld\n", (long) sb.st_ino);
    printf("Mode: %lo (octal)\n", (unsigned long) sb.st_mode);
    printf("Link count: %ld\n", (long) sb.st_nlink);
    printf("Ownership: UID=%ld   GID=%ld\n", (long) sb.st_uid,
        (long) sb.st_gid);
    printf("Preferred I/O block size: %ld bytes\n", (long) sb.st_blksize);
    printf("File size:                %lld bytes\n", (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n", (long long) sb.st_blocks);
    printf("Last status change:       %i", ctime(&sb.st_ctime));
    printf("Last file access:         %i", ctime(&sb.st_atime));
    printf("Last file modification:   %i", ctime(&sb.st_mtime));
    return EXIT_SUCCESS;               
}
