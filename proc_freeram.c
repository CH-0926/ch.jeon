#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>
#include <unistd.h>

#include "proc_freeram.h"

#define MEMINFO_FILE "/proc/meminfo"

long get_free_ram(const char *meminfo_path) {
    FILE *file = NULL;
    char line[256] = {0};
    long free_ram = -1;

    if (meminfo_path == NULL) {
        meminfo_path = MEMINFO_FILE;
    }

    file = fopen(meminfo_path, "r");
    if (file == NULL) {
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemFree: %ld KB", &free_ram) == 1) {
            fclose(file);
            return free_ram;
        }
    }

    fclose(file);
    return -1;
}