/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-25.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

static int debug_flag;
struct global_args {
    char *username;
    char *hostname;
    char *tty;
    char *ascii;
    char *utmp;
    char *wtmp;
    char *lastlog;
} global_args;
static const char *opt_string = "u:h:t:a:bwlV?";
static const struct option long_opt[] = {
    { "username",   required_argument,  NULL,           'u'},
    { "hostname",   required_argument,  NULL,           'h'},
    { "tty",        required_argument,  NULL,           't'},
    { "ascii",      required_argument,  NULL,           'a'},
    { "utmp",       optional_argument,  NULL,           'b'},
    { "wtmp",       optional_argument,  NULL,           'w'},
    { "lastlog",    optional_argument,  NULL,           'l'},
    { "debug",      no_argument,        &debug_flag,    1},
    { "version",    no_argument,        NULL,           'V'},
    { "help",       no_argument,        NULL,           0},
    { NULL,         no_argument,        NULL,           0},
};

int main(int argc, char **argv) {
    int opt = 0;
    int opt_index = 0;
    
    global_args.username    = NULL;
    global_args.hostname    = NULL;
    global_args.tty         = NULL;
    global_args.ascii       = NULL;
    global_args.utmp        = UTMP_FILE;
    global_args.wtmp        = WTMP_FILE;
    global_args.lastlog     = _PATH_LASTLOG;
    
    if (geteuid() != 0) {
        fprintf(stderr, "You must be root to run this program!\n");
        return EXIT_FAILURE;
    }

    opt = getopt_long(argc, argv, opt_string, long_opt, &opt_index);
    
    while(opt != -1){
        switch(opt) {
            case 'u':
                global_args.username = optarg;
                break;
            case 'h':
                global_args.hostname = optarg;
                break;
            case 't':
                global_args.tty = optarg;
                break;
            case 'a':
                global_args.ascii = optarg;
                break;
            case 'b':
                break;
            case 'w':
                break;
            case 'l':
                break;
            case 'V':
                display_version();
                break;
            case '?':
                display_header();
                display_usage();
                break;
            case 0:
            default:
                break;
        }
        
        opt = getopt_long(argc, argv, opt_string, long_opt, &opt_index);
    }
    
    if(debug_flag) {
        fprintf(stdout, "username: \t %s\n"
            "hostname: \t %s\n"
            "tty: \t ‰s\n"
            "ascii: \t %s\n"
            "utmp: \t %s\n"
            "wtmp: \t %s\n"
            "lastlog: \t %s\n",
             global_args.username,
             global_args.hostname,
             global_args.tty,
             global_args.ascii,
             global_args.utmp,
             global_args.wtmp,
             global_args.lastlog);
    }
    
    return EXIT_SUCCESS;
}


void display_usage() {
    fprintf(stdout, "Usage: lapse [OPTIONS]...\n"
        " -u, --username=username \t username or login\n"
        " -h, --host=hostname \t hostname or IP\n"
        " -t, --tty=tty \t \n"
        "\n"
        " -a, --ascii=path \t \n"
        " -b, --utmp[=PATH] \t utmp file path\n"
        " -w, --wtmp[=PATH] \t wtmp file path\n"
        " -l, --lastlog[=PATH] \t \n"
        "\n"
        " --debug \t active debug mode\n"
        " -V, --version \t print lapse version\n"
        " --help \t show this help screen and exit\n"
        );
}

void display_header() {
    fprintf(stdout, "lapse - clean logs\n");
}

void display_version() {
    fprintf(stdout, "lapse %s", VERSION);
}