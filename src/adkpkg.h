#ifndef LOGS_H
#define LOGS_H

#define VERSION "adkpkg v0.1"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


#define bool char
#define true 255
#define false 0
// better than stdbool.h

#define BOLD_RED "\033[1;31m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_GREEN "\033[1;32m"
#define RESET "\033[0m"
#define LAST_STR "\r"

#define logerr(msg) fputs(BOLD_RED "ERROR: " RESET msg "\n", stderr)
#define log(msg) printf(BOLD_YELLOW "=> " RESET msg "\n")


void *loadingTh(void *args) {
    const char *loading[] = {"|", "/", "-", "\\"};
    int i;

    while (1) {
        printf(LAST_STR BOLD_YELLOW "=> " RESET "%s... %s", (char*)args, loading[i % 4]);
        fflush(stdout);
        usleep(200000);

        i++;
        if (i == 4) i=0;
    }
}

void clrLoading(bool isCorrect, char *str) {
    if (isCorrect)
    printf(LAST_STR BOLD_YELLOW "=> " RESET "%s... " BOLD_GREEN "Done!" RESET);

    else
    printf(LAST_STR BOLD_YELLOW "=> " RESET "%s... " BOLD_RED "Error!" RESET);

    printf("\n\n");
    fflush(stdout);
}

#endif // LOGS_H
