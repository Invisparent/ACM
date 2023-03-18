#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int res = 5000 - a * b / 2 - (100 - a) * (100 - b) / 2 - (100 - a) * b;
    printf("%d", res);

    return 0;
}
