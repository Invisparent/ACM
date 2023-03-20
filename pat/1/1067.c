#include <stdio.h>

int main() {
    double a, c;
    int b;
    scanf("%lf %d %lf", &a, &b, &c);

    if (b)
        a *= 1.26;
    else
        a *= 2.455;

    printf("%.2lf ", a);

    if (a >= c)
        printf("T_T");
    else
        printf("^_^");

    return 0;
}
