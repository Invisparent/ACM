#include <stdio.h>

#define IVS_PI 3.14

int main() {
    double h, r;
    scanf("%lf%lf", &h, &r);
    h /= 10;
    r /= 10;
    double v = IVS_PI * r * r * h;
    if (20 / v == (int) (20 / v))
        printf("%d", (int) (20 / v));
    else
        printf("%d", (int) (20 / v + 1));
    return 0;
}
