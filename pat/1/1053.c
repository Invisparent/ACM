#include <stdio.h>

const char str[6] = "Wang!";

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    a += b;

    for (int i = 0; i < a; ++i)
        for (int j = 0; j < 5; ++j)
            putchar(str[j]);

    return 0;
}
