/*
 * Lapse - Log cleaning tool
 *
 * Created by Romain Delmotte on 2011-08-25.
 * Copyright (c) 2011 LiveFyre. All rights reserved.
 *
 */

#ifndef _LAPSE_H_
#define _LAPSE_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

void usage();
void head();

int clean_lastlog(char *filename);

#endif