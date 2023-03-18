#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    double res = a / b / b;
    printf("%.1lf\n", res);

    if (res > 25)
        printf("PANG");
    else
        printf("Hai Xing");

    return 0;
}
