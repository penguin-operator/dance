#include <stdio.h>

int main() {
    FILE* log = fopen("/var/log/test.log", "w");
    fprintf(log, "hello world!\n");
    fclose(log);
    return 0;
}
