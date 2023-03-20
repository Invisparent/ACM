#include <stdio.h>

int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", fact(a + b));

    return 0;
}
