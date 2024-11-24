#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *logLoading(void *args) {
    const char *loading[] = {"|", "/", "-", "\\"};
    int i;

    while (1) {
        printf("\r%s... %s", (char*) args, loading[i % 4]);
        fflush(stdout);
        usleep(200000);

        i++;
        if (i == 4) i=0;
    }
}

int main() {
    pthread_t loading;
    pthread_create(&loading, 0, logLoading, "Copying template");

    sleep(3);

    pthread_cancel(loading);

    printf("\rLoading... Done!\n");
    printf("Loading complete!\n");
    return 0;
}

