/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-29.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

int buf_stat(char *filename, struct stat *st) {
    if (stat(filename, st) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

int set_stat(char *filename, struct stat *st) {
    struct timeval times[2];
    
    /*if(chmod(filename, st->st_mode) == -1) {
        perror("chmod");
        return EXIT_FAILURE;
    }
    
    if(chown(filename, st->st_uid, st->st_gid) == -1) {
        perror("chown");
        return EXIT_FAILURE;
    }*/
    
    times[0].tv_sec     = st->st_atime;
    times[0].tv_usec    = 0;
    times[1].tv_sec     = st->st_mtime;
    times[1].tv_usec    = 0;
    
    if(utimes(filename, times) == -1) {
        perror("utimes");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}