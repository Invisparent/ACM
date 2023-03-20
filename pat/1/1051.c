#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%.2lf", a * (double) b / 10);

    return 0;
}
