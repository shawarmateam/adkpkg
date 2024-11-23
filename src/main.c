#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    fputs("ERROR: This type of package in unavariable\n", stderr);
    exit(1);
}



bool mkNew(char *name, short type) {
    switch (type) {
        case 0:
            printf("типа сделали пакет\n");
            break;
    }
    return true;
}

bool delPkg(char *name, short type) {
    short type_len;
    char *type_str = getPkgName(type, &type_len);

    short rm_cmd_len = type_len
        +16
        +strlen(name);
    char *rm_cmd = malloc(rm_cmd_len); // 'rm -rf ~/apps/c/test'

    snprintf(rm_cmd, rm_cmd_len, "rm -rf ~/apps/%s/%s", type_str, name);
    printf("rm_cmd: '%s'\n", rm_cmd);
    return true;
}

void checkTFA(int argv) {
    if (argv < 4) {
        printf("ERROR: Too few arguments.\n");
        exit(1);
    }
}

int main(int argv, char **argc) {
    checkTFA(argv);
    
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


    return 0;
}
