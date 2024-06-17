#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proc_freeram.h"

long get_free_ram() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        return -1;
    }

    char line[256];
    long free_ram = -1;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemFree: %ld kB", &free_ram) == 1) {
            fclose(file);
            return free_ram * 1024; // Convert kB to bytes
        }
    }

    fclose(file);
    return -1;
}


