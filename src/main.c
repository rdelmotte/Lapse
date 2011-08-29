/*
* Lapse - Log cleaning tool
*
* Created by Romain Delmotte on 2011-08-25.
* Copyright (c) 2011. All rights reserved.
*
*/

#include "lapse.h"

static int debug_flag;
static const char *opt_string = "u:h:t:a:bwlV?";
struct global_args {
    char *username;
    char *hostname;
    char *tty;
    char *ascii_file;
    int utmp;
    int wtmp;
    int lastlog;
} global_args;
static const struct option long_opt[] = {
    { "username",   required_argument,  NULL,           'u'},
    { "hostname",   required_argument,  NULL,           'h'},
    { "tty",        required_argument,  NULL,           't'},
    { "ascii",      required_argument,  NULL,           'a'}
    { "utmp",       no_argument,        NULL,           'b'},
    { "wtmp",       no_argument,        NULL,           'w'},
    { "lastlog",    no_argument,        NULL,           'l'},
    { "debug",      no_argument,        &debug_flag,    0},
    { "version",    no_argument,        NULL,           'V'}
    { "help",       no_argument,        NULL,           0},
    { NULL,         no_argument,        NULL,           0},
};

int main(int argc, char **argv) {
    int opt;
    int opt_index = 0;

    if (geteuid() != 0) {
        fprintf(stderr, "You must be root to run this program!\n");
        return EXIT_FAILURE;
    }

    opt = getopt_long(argc, argv, opt_sting, long_opt, &opt_index);
    
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
                global_args.ascii_file = optarg;
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
        
        opt = getopt_long(argc, argv, opt_sting, long_opt, &opt_index);
    }
    
    return EXIT_SUCCESS;
}


void display_usage() {
    fprintf(stdout, "Usage: lapse [options...]\n"
        "Options:\n"
        " -u --username <username>\tusername or login\n"
        " -h --host <hostname>\thostname or IP\n"
        " -t --tty <tty>\t\n"
        " -a --ascii <filename>\t\n"
        " -b --utmp\tutmp file path\n"
        " -w --wtmp\twtmp file path\n"
        " -l --lastlog\t\n"
        " --debug\tactive debug mode\n"
        " -V --version\tprint lapse version\n"
        " --help\tshow this help screen and exit\n"
        );
}

void display_header() {
    fprintf(stdout, "lapse - clean logs\n");
}

void display_version() {
    fprintf(stdout, "lapse %s", VERSION);
}