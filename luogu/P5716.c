#include <stdio.h>

#define IVS_D 30

const int offset[13] = {-1, 1, -2, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};

int main() {
    int y, m;
    scanf("%d%d", &y, &m);
    int lunar = (y % 4 == 0 && y % 100) || y % 400 == 0;
    printf("%d", IVS_D + offset[m] + (lunar && m == 2));
    return 0;
}
