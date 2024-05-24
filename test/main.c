#include <stdio.h>

int main() {
    FILE* log = fopen("/var/log/test.log", "w");
    printf("hello world!\n");
    return 0;
}
