#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int t = (c - a) * 60 + (d - b);
    if (t < 60)
        putchar('0');
    else
        printf("%d ", t / 60);
    printf("%d", t % 60);
    return 0;
}
