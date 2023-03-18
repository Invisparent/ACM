#include <stdio.h>

#define IVS_N 7

int main() {
    int a, b;
    // ...
    //int res = 0, maxAng = 8;
    int res = -1, maxAng = 8;
    for (int t = 0; t < IVS_N; ++t) {
        scanf("%d%d", &a, &b);
        if (a + b > maxAng) {
            res = t;
            maxAng = a + b;
        }
    }
    // ...
    //printf("%d", res);
    printf("%d", res + 1);
    return 0;
}
