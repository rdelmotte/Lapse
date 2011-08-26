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

#ifdef HAVE_LASTLOG_H
#include <lastlog.h>
#endif

#define VERSION "0.1"

void usage();
void head();

#endif