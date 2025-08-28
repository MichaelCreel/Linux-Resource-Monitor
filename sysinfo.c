#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int main() {
    //USER AND PROCESS INFORMATION
    printf("User ID: %d\n", getuid());
    printf("Group ID: %d\n", getgid());
    printf("Process ID: %d\n", getpid());

    //CPU INFORMATION
    FILE *cpu = fopen("/proc/cpuinfo", "r");
    if (cpu) {
        printf("\n<--- CPU INFORMATION --->\n");
        char line[256];
        while (fgets(line, sizeof(line), cpu)) {
            if (strncmp(line, "model name", 10) == 0 || strncmp(line, "cpu cores", 9) == 0) {
                printf("%s", line);
            }
        }
        fclose(cpu);
    }

    //MEMORY INFORMATION
    FILE *mem = fopen("/proc/meminfo", "r");
    if (mem) {
        printf("\n<--- MEMORY INFORMATION --->\n");
        char label[64];
        unsigned long mem_kb = 0;
        while (fscanf(mem, "%63s %lu kb\n", label, &mem_kb) == 2) {
            if (strcmp(label, "MemTotal:") ==0) {
                printf("Total Memory: %.2f GB\n", mem_kb / 1024.0 / 1024.0);
            } else if (strcmp(label, "MemFree:") == 0) {
                printf("Free Memory: %.2f GB\n", mem_kb / 1024.0 / 1024.0);
            }
        }
        fclose(mem);
    }

    return 0;
}