#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proc_freeram.h"
#include "freeram.h"
#include <unistd.h>

char *convert_bytes(void) {
    long free_ram = get_free_ram("/proc/meminfo");
    if (free_ram == -1) {
        printf("Failed to read freeram\n");
        return NULL; // 프로그램 종료
    }

    char buf[1024] = {0};
    ssize_t pos = 0;
    double byte_BT = free_ram * 1024;
    double byte_KB = free_ram;
    double byte_MB = byte_KB / 1024.0;
    double byte_GB = byte_MB / 1024.0;
    double byte_TB = byte_GB / 1024.0;

    pos += snprintf(buf + pos, sizeof(buf) - pos, "Freeram: %.2f bytes\n", byte_BT);
    pos += snprintf(buf + pos, sizeof(buf) - pos, "Freeram: %.2f KB\n", byte_KB);
    pos += snprintf(buf + pos, sizeof(buf) - pos, "Freeram: %.2f MB\n", byte_MB);
    pos += snprintf(buf + pos, sizeof(buf) - pos, "Freeram: %.2f GB\n", byte_GB);
    pos += snprintf(buf + pos, sizeof(buf) - pos, "Freeram: %.2f TB\n", byte_TB);

    return strdup(buf);
}

#ifndef UNIT_TESTING
int main() {
    char *free_ram_str = NULL;
    free_ram_str = convert_bytes();
    if (free_ram_str == NULL) {
        fprintf(stderr, "Failed to read freeram\n");
        return 1;
    }

    printf("%s", free_ram_str);
    free(free_ram_str); // strdup() 함수를 사용하여 동적으로 메모리를 할당, 메모리 누수 발생
    return 0;
}
#endif /* UNIT_TESTING */
