#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
        char line[256];
        while (fgets(line, sizeof(line), mem)) {
            if (strncmp(line, "MemTotal", 8) == 0 || strncmp(line, "MemFree", 7) == 0) {
                printf("%s", line);
            }
        }
        fclose(mem);
    }

    return 0;
}