#include <stdio.h>

int main() {
    int s, v;
    scanf("%d%d", &s, &v);
    int r;
    if (s % v)
        r = s / v + 1;
    else
        r = s / v;
    int t = 60 * 32 - r - 10;
    t %= 60 * 24;
    if (t / 60 < 10)
        putchar('0');
    printf("%d:", t / 60);
    if (t % 60 < 10)
        putchar('0');
    printf("%d", t % 60);
    return 0;
}
