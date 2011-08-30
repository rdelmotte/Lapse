/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-30.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

int clean_utmp(char *filename, char *username) {
    int fd;
    struct utmp ut;
    
    /*if(!strcmp(username, "")) {
        fprintf(stdout, "username can't be NULL\n");
        return EXIT_FAILURE;
    }*/
    
    if((fd = open(filename, O_RDWR)) == -1) {
        perror("open");
        return EXIT_FAILURE;
    }
    
    while(read(fd, &ut, sizeof(struct utmp)) > 0) {
        if (!strncmp(ut.ut_name, username, strlen(username))) {
            bzero(&ut, sizeof(ut));
            lseek(fd, -(sizeof (ut)), SEEK_CUR);
            write(fd, &ut, sizeof(ut));
        }
    }
    
    close(fd);
    
    return EXIT_SUCCESS;
}