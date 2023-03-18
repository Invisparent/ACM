#include <stdio.h>

int main() {
    printf("The winner is ");

    int a, b, x, y, z;
    scanf("%d%d%d%d%d", &a, &b, &x, &y, &z);

    if (x == y && y == z) {
        if (x)
            printf("b: %d + 3", b);
        else
            printf("a: %d + 3", a);
        return 0;
    }

    if (a > b)
        printf("a: %d + %d", a, !x + !y + !z);
    else
        printf("b: %d + %d", b, x + y + z);

    return 0;
}
