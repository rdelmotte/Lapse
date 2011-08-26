/*
 * Lapse - Log cleaning tool
 *
 * Created by Romain Delmotte on 2011-08-25.
 * Copyright (c) 2011 LiveFyre. All rights reserved.
 *
 */

#include "lapse.h"

int main(int argc, char **argv) {
    if (geteuid() != 0) {
        fprintf(stderr, "You must be root to run this program!\n");
        return EXIT_FAILURE;
    }
    
    char arg;
    
    while ((arg = getopt(argc, argv, "hi:nl")) != EOF) {
        switch (arg) {
            case 'h':
                head();
                usage();
                return EXIT_SUCCESS;
                break;
            case 'i':
                printf("%s", optarg);
                break;
            case 'n':
                break;
            case 'l':
                lastlog();
                break;
            case '?':
                printf("???");
                break;
            default:
                head();
                printf("fuck");
                break;
        }
    }
    return EXIT_SUCCESS;
}

void usage() {
    fprintf(stdout, "Usage: lapse [options...]\n"
                    "Options:\n"
                    " -u/--username <username>\tusername or login\n"
                    " -h/--host <hostname>\thostname or IP\n"
                    " -t/--tty <tty>\tdesc\n"
                    " -l/--lastlog\t"
                    " --utmp [/var/log/utmp]\tutmp file path\n"
                    " --wtmp [/var/log/wtmp]\twtmp file path\n"
                    " -h/--help\tprint this help screen\n"
    );
}

void head() {
    fprintf(stdout, "Lapse %s - Log cleaning tool\n", VERSION);
}