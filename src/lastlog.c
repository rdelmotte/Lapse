/*
 * Lapse - Log cleaning tool
 *
 * Created by Romain Delmotte on 2011-08-25.
 * Copyright (c) 2011 LiveFyre. All rights reserved.
 *
 */

#include "lapse.h"

int lastlog(void) {
    fprintf(stdout, "lastlog file path: %s\n", UTMP_FILE);
    return EXIT_SUCCESS;
}