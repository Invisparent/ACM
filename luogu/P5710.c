#include <stdio.h>
#include <stdint.h>

int main() {
    int x;
    scanf("%d", &x);
    uint8_t a = !(x % 2);
    uint8_t b = x > 4 && x <= 12;
    printf("%d %d %d %d", a && b, a || b, a ^ b, !a && !b);
    return 0;
}
