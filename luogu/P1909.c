#include <stdio.h>

int n;

int i32mo3(int a, int b, int c) {
    if (a < b) {
        if (a < c)
            return a;
        else
            return c;
    } else {
        if (b > c)
            return c;
        else
            return b;
    }
}

int priceCalc(int p, int w) {
    if (!(n % p))
        return (n / p) * w;
    else
        return (n / p + 1) * w;
}

int main() {
    scanf("%d", &n);
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d", i32mo3(priceCalc(a, b), priceCalc(c, d), priceCalc(e, f)));
    return 0;
}
