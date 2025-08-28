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

        unsigned long mem_total = 0;
        unsigned long mem_free = 0;
        char label[64];
        unsigned long value;

        while (fscanf(mem, "%63s %lu kB\n", label, &value) == 2) {
            if (strcmp(label, "MemTotal:") == 0) {
                mem_total = value;
            } else if (strcmp(label, "MemAvailable:") == 0) {
                mem_free = value;
            }
            if (mem_total && mem_free) {
                break;
            }
        }
        fclose(mem);

        float mem_total_gb = mem_total / 1024.0 / 1024.0;
        float mem_free_gb = mem_free / 1024.0 / 1024;
        float mem_used_gb = mem_total_gb - mem_free_gb;
        float mem_used_percent = (mem_used_gb / mem_total_gb) * 100.0;

        printf("Used Memory: %.2f%% (%.2f GB)\n\n", mem_used_percent, mem_used_gb);
        printf("Free Memory: %.2f GB (%.2f%%)\n", mem_free_gb, 100.0 - mem_used_percent);
        printf("Total Memory: %.2f GB\n", mem_total_gb);
    }

    return 0;
}