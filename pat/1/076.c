#include <stdio.h>

int main() {
    double n, m;
    scanf("%lf %lf\n", &n, &m);
    double w;
    for (int t = 0; t < n; ++t) {
        scanf("%lf\n", &w);
        if (w < m)
            printf("On Sale! %.1lf\n", w);
    }

    return 0;
}
