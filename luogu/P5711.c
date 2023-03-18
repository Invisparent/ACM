#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if ((n % 4 == 0 && n % 100) || n % 400 == 0)
        putchar('1');
    else
        putchar('0');
    return 0;
}
