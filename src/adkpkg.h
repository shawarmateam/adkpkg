#ifndef LOGS_H
#define LOGS_H

#define VERSION "adkpkg v0.1"

#include <stdio.h>
#include <stdlib.h>


#define BOLD_RED "\033[1;31m"
#define BOLD_YELLOW "\033[1;33m"
#define RESET "\033[0m"

#define logerr(msg) fputs(BOLD_RED "ERROR: " RESET msg "\n", stderr)
#define log(msg) printf(BOLD_YELLOW "=> " RESET msg "\n")


#endif // LOGS_H
