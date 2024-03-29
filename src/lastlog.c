/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-25.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

int clean_lastlog(char *filename, char *username) {
    int fd;
    struct lastlog ll;
    struct passwd *pwd;
    
    if((fd = open(filename, O_RDWR)) == -1) {
        perror(filename);
        return EXIT_FAILURE;
    }
    
    if((pwd = getpwnam(username)) == NULL) {
        perror(username);
        return EXIT_FAILURE;
    }
    
    if(lseek(fd,(long)pwd->pw_uid * sizeof(struct lastlog), SEEK_SET) == -1) {
        perror("lseek");
        return EXIT_FAILURE;
    }
    
    bzero(&ll, sizeof(ll));
    write(fd, &ll, sizeof(ll));
    
    close(fd);
    
    return EXIT_SUCCESS;
}