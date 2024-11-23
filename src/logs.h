#ifndef LOGS_H
#define LOGS_H

#include <stdio.h>
#include <stdlib.h>


#define BOLD_RED "\033[1;31m"
#define RESET "\033[0m"

#define logerr(msg) fputs(BOLD_RED "ERROR: " RESET msg "\n", stderr)

#endif // LOGS_H
