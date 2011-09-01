/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-30.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

int clean_utmp(char *filename, char *username) {
    int fd, fd2;
    struct utmp ut;
    char template[] = TEMPLATE;
    
    if((fd2 = mkstemp(template)) == -1) {
        perror(template);
        return EXIT_FAILURE;
    }
    
    printf("tmp(%s) username(%s)\n", template, username);
    
    /*if(!strcmp(username, "")) {
        fprintf(stdout, "username can't be NULL\n");
        return EXIT_FAILURE;
    }*/
    
    if((fd = open(filename, O_RDONLY)) == -1) {
        perror(filename);
        return EXIT_FAILURE;
    }
    
    while(read(fd, &ut, sizeof(struct utmp)) > 0) {
        if (strcmp(ut.ut_line, username))
            write(fd2, &ut, sizeof(ut));
    }
    
    close(fd);
    close(fd2);
    
    return EXIT_SUCCESS;
}