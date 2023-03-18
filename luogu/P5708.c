#include <stdio.h>
#include <math.h>

int main() {
//    int a, b, c;
//    scanf("%d%d%d", &a, &b, &c);
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double p = 0.5 * (a + b + c);
    double res = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1lf", res);
    return 0;
}
