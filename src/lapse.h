/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-25.
* Copyright (c) 2011. All rights reserved.
*
*/

#ifndef _LAPSE_H_
#define _LAPSE_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include <utmp.h>
#include <lastlog.h>

#ifndef UTMP_FILE
#define UTMP_FILE "/var/run/utmp"
#endif    

#ifndef WTMP_FILE
#define WTMP_FILE "/var/log/wtmp"
#endif

#ifndef _PATH_LASTLOG
#define _PATH_LASTLOG "/var/log/lastlog"
#endif

#define VERSION "0.1"
#define MESSAGES_FILE "/var/log/messages"
#define SECURE_FILE "/var/log/auth.log"

void display_header();
void display_usage();
void display_version();
int buf_stat(char *filename);
int set_stat();
int clean_utmp(char *filename, char *username);
int clean_lastlog(char *filename, char *username);

#endif