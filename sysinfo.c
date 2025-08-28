#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main() {
    printf("User ID: %d\n", getuid());
    printf("Group ID: %d\n", getgid());
    printf("Process ID: %d\n", getpid());

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
}