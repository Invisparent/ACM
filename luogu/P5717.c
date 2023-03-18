#include <stdio.h>

void ivsSwap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}

void ivsSort(int *a, int *b, int *c) {
    if (*a > *b)
        ivsSwap(a, b);
    if (*a > *c)
        ivsSwap(a, c);
    if (*b > *c)
        ivsSwap(b, c);
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ivsSort(&a, &b, &c);
    if (a + b <= c) {
        printf("Not triangle\n");
        return 0;
    }
    if (a * a + b * b == c * c)
        printf("Right triangle\n");
    else if (a * a + b * b > c * c)
        printf("Acute triangle\n");
    else
        printf("Obtuse triangle\n");
    if (a == b || b == c) {
        printf("Isosceles triangle\n");
        if (a == b && b == c)
            printf("Equilateral triangle\n");
    }
    return 0;
}
