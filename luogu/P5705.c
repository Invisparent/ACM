#include <stdio.h>
#include <string.h>

int main() {
    char str[6];
    scanf("%s", str);
    int idx = (int) strlen(str) - 1;
    while (idx >= 0) {
        putchar(str[idx]);
        --idx;
    }
    return 0;
}
