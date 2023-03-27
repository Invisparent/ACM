#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int resA = a / c;
    int resB = b / c;
    if (a % c)
        ++resA;
    if (b % c)
        ++resB;

    printf("%lld", (long long) resA * resB);

    return 0;
}
