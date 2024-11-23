#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool char
#define true 255
#define false 0
// better than stdbool.h

bool mkNew(char *name, short type) {
    switch (type) {
        case 0:
            printf("типа сделали пакет\n");
            break;
    }
    return true;
}

bool delPkg(char *name, short type) {
    char *type_str;
    short type_len;

    switch (type) {
        case 0:
            type_str = malloc(2);  type_len=1;
            type_str = "c";
            break;
    }

    char *rm_cmd; // 'rm -rf ~/apps/c/test'
    short rm_cmd_len = type_len
        +16
        +strlen(name);

    snprintf(rm_cmd, 16, "rm -rf ~/apps/%s/%s", type_str, name);
    printf("rm_cmd: '%s\n'", rm_cmd);
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
