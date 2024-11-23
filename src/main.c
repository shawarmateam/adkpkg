#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logs.h"

#define bool char
#define true 255
#define false 0
// better than stdbool.h

char* getPkgName(short type, short *len) {
    switch (type) {
        case 0:
            *len = 1;
            return "c";
    }

    //fputs(BOLD_RED "ERROR:" RESET " This type of package in unavariable\n", stderr);
    logerr("This type of package in unavariable.");
    exit(1);
}


bool mkNew(char *name, short type) {
    switch (type) {
        case 0:
            log("Creating package...");
            break;
        default:
            logerr("Package type is unavariable.");
    }
    return true;
}

bool delPkg(char *name, short type) {
    short type_len;
    char *type_str = getPkgName(type, &type_len);

    short rm_path_len = type_len
        +9
        +strlen(name);
    char *rm_path = malloc(rm_path_len); // 'rm -rf ~/apps/c/test'

    snprintf(rm_path, rm_path_len, "~/apps/%s/%s/", type_str, name);
    printf("rm_path: '%s'\n", rm_path);

    short check_pkg_len = rm_path_len+20;
    char *check_pkg = malloc(check_pkg_len);
    snprintf(check_pkg, check_pkg_len, "ls %s > /dev/null 2>&1", rm_path);

    int status = system(check_pkg);

    if (status) {
        fputs(BOLD_RED "ERROR:" RESET " Can't remove package that doesn't exists.\n", stderr);
        exit(1);
    }

    short rm_pkg_cmd_len = rm_path_len+7;
    char *rm_pkg_cmd = malloc(rm_pkg_cmd_len);
    snprintf(rm_pkg_cmd, rm_pkg_cmd_len, "rm -rf %s", rm_path);

    system(rm_pkg_cmd);

    return true;
}

void checkTFA(int argv, int min) {
    if (argv < min) {
        logerr("Too few arguments. See --help.");
        exit(1);
    }
}

int main(int argv, char **argc) {
    checkTFA(argv, 4);
    
    if (strcmp(argc[1], "new") == 0) {
        if (strcmp(argc[2], "c") == 0) {
            mkNew(argc[3], 0);
        }
    }

    else if (strcmp(argc[1], "remove") == 0) {
        if (strcmp(argc[2], "c") == 0) {
            delPkg(argc[3], 0);
        }
    }

    else {
        logerr("Incorrect args. See --help.");
        exit(1);
    }
    return 0;
}
