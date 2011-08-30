/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-29.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

int buf_stat(char *filename) {
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
    printf("Last status change:       %s", &sb.st_ctime);
    printf("Last file access:         %s", &sb.st_atime);
    printf("Last file modification:   %s", &sb.st_mtime);
    return EXIT_SUCCESS;
}

int set_stat() {
    /*struct timeval ftime[2], otime, ntime;

if (chmod(argv[1],statbuf.st_mode)) {
fprintf(stderr,"stat: No permission to change mode or no such file\n");
return EXIT_FAILURE;
}

if (chown(argv[1],statbuf.st_uid,statbuf.st_gid)) {
fprintf(stderr, 
"stat: No permission to change owner or no such file\n");
return EXIT_FAILURE;
}

ftime[0].tv_sec	= statbuf.st_atime;
ftime[1].tv_sec	= statbuf.st_mtime;
ntime.tv_sec	= statbuf.st_ctime;

ftime[0].tv_usec=ftime[1].tv_usec=ntime.tv_usec=0;


if (gettimeofday(&otime,&tzp)) {
fprintf(stderr, "fixer: Can't read time of day\n");
return EXIT_FAILURE;
}

if (settimeofday(&ntime,&tzp)) {
fprintf(stderr, "fixer: Can't set time of day\n");
}

if (utimes(argv[1],ftime)) {
fprintf(stderr, "stat: Can't change modify time\n");
return EXIT_FAILURE;
}
settimeofday(&otime,&tzp);*/

    return EXIT_SUCCESS;
}