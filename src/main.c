#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "adkpkg.h"

#define bool char
#define true 255
#define false 0
// better than stdbool.h
char *HOME;

void logAdd(const char *textToAdd) {
    char *log_path = "/apps/c/adkpkg/logs";

    FILE *file = fopen(strcat(HOME, log_path), "a");
    if (file == NULL) {
        logerr("Unavariable to open the log file.");
        log("Aborting...");
        exit(1);
    }

    if (fputs("\n", file) == EOF) {
        logerr("Unavariable to write into log file.");
        log("Aborting...");
        fclose(file);
        exit(1);
    } else {
        fputs(textToAdd, file);
        fputs("\n", file);
    }

    fclose(file);
}

char* getPkgName(short type, short *len) {
    switch (type) {
        case 0:
            *len = 1;
            return "c";
    }

    logerr("This type of package in unavariable.");
    exit(1);
}


bool mkNew(char *name, short type) {
    short type_len = 0;
    char *type_str = getPkgName(type, &type_len);
    short name_len = strlen(name);

    log("Copying template to package...");

    short cp_template_len = 95
        +name_len
        +(type_len*5)
        +(strlen(HOME)*5);

    char *cp_template = malloc(cp_template_len);
    snprintf(cp_template, cp_template_len, "cp -r %s/apps/c/adkpkg/%s-pkg/ %s/apps/%s/ > %s/apps/c/adkpkg/logs 2>&1 && mv %s/apps/%s/%s-pkg/ %s/apps/%s/%s/", HOME, type_str, HOME, type_str, HOME, HOME, type_str, type_str, HOME, type_str, name);

    logAdd(cp_template);
    int status = system(cp_template);
    if (status) {
        logerr("Unavariable to copy template to package.");
        log("Aborting...");
        exit(1); // TODO: сделать очисту памяти по аборту/завершению
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
    if (argv < min+1) {
        logerr("Too few arguments. See --help.");
        exit(1);
    }
}

int main(int argv, char **argc) {
    checkTFA(argv, 1);
    system("touch ~/apps/c/adkpkg/logs");
    HOME = malloc(1+strlen(getenv("HOME")));
    HOME = getenv("HOME");

    if (getuid() == 0) {
        logerr("Do not run as root.");
        exit(1);
    }

    for(int i=0; i<argv; ++i) {
        if (i == 0) continue;

        if (0==strcmp(argc[i], "--help") || 0==strcmp(argc[i], "-h")) {
            printf(
VERSION "\n"
"Package Manager by adk.\n\n"
"Usage: adkpkg [ -h|--help ] [ -v|--version ]\n\n"
"OPTIONS:\n"
"    new       Create new local repo.\n"
"    get       Get repo.\n"
"    remove    Remove local repo.\n"
);
            exit(0);
        }
    }

    if (strcmp(argc[1], "new") == 0) {
        checkTFA(argv, 3);
        if (strcmp(argc[2], "c") == 0) {
            mkNew(argc[3], 0);
        }
    }

    else if (strcmp(argc[1], "remove") == 0) {
        checkTFA(argv, 3);
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
