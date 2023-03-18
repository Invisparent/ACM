#include <stdio.h>

int main() {
    int m, t, s;
    scanf("%d%d%d", &m, &t, &s);
    if (m * t <= s) {
        putchar('0');
        return 0;
    }
    if (t == 0) {
        printf("%d", m);
        return 0;
    }
    if (s % t)
        printf("%d", m - s / t - 1);
    else
        printf("%d", m - s / t);
    return 0;
}
