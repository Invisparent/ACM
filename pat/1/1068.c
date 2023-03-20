#include <stdio.h>

int main() {
    int n;
    double res = 0, d;
    scanf("%d\n", &n);

    for (int t = 0; t < n; ++t) {
        scanf("%lf", &d);
        res += 1 / d;
    }

    printf("%.2lf", n / res);

    return 0;
}
