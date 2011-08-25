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
    
    while ((arg = getopt(argc, argv, "hi:n")) != EOF) {
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
                    " -u <username>\tdesc\n"
                    " -h <hostname>\tdesc\n"
                    " -t <tty>\tdesc\n"
                    " -h\tprint this help screen\n"
    );
}

void head() {
    fprintf(stdout, "Lapse %s - Log cleaning tool\n", VERSION);
}