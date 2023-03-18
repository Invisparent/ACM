#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double res;
    if (n > 150)
        if (n > 400)
            res = 183.52 + 0.5663 * (n - 400);
        else
            res = 66.945 + 0.4663 * (n - 150);
    else
        res = 0.4463 * n;
    printf("%.1lf", res);
    return 0;
}
