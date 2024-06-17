#include <stdio.h>
#include <string.h>
#include "proc_freeram.h"

double convert_bytes(long bytes, const char *unit) {
    if (unit == NULL) {
        return -1.0;
    }

    if (strcmp(unit, "KB") == 0) {
        return bytes / 1024.0;
    } else if (strcmp(unit, "MB") == 0) {
        return bytes / (1024.0 * 1024.0);
    } else if (strcmp(unit, "GB") == 0) {
        return bytes / (1024.0 * 1024.0 * 1024.0);
    } else if (strcmp(unit, "TB") == 0) {
        return bytes / (1024.0 * 1024.0 * 1024.0 * 1024.0);
    } else {
        return bytes;
    }
}

#ifndef UNIT_TESTING
int main() {
    long free_ram = get_free_ram();
    if (free_ram == -1) {
        printf("Failed to retrieve free RAM\n");
    } else {
        printf("Free RAM: %ld bytes\n", free_ram);
    }

    // Example usage of convert_bytes function
    double free_ram_kb = convert_bytes(free_ram, "KB");
    double free_ram_mb = convert_bytes(free_ram, "MB");
    double free_ram_gb = convert_bytes(free_ram, "GB");

    printf("Free RAM: %.2f KB\n", free_ram_kb);
    printf("Free RAM: %.2f MB\n", free_ram_mb);
    printf("Free RAM: %.2f GB\n", free_ram_gb);

    return 0;
}
#endif /* UNIT_TESTING */

