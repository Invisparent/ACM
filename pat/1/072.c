#include <stdio.h>
#include <stdint.h>

uint8_t rec[10];
int data[5][5];

int resCheck[] = {10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};

int main() {
    int zx, zy;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j) {
            scanf("%d", &data[i][j]);
            if (data[i][j] == 0) {
                zx = i;
                zy = j;
            } else
                rec[data[i][j]] = 1;
        }

    for (int t = 1; t <= 9; ++t)
        if (!rec[t])
            data[zx][zy] = t;

    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("%d\n%d\n%d\n", data[x1][y1], data[x2][y2], data[x3][y3]);

    int c;
    scanf("%d", &c);

    int res;
    if (c <= 3) {
        res = data[c][1] + data[c][2] + data[c][3];
    } else if (c <= 6) {
        c -= 3;
        res = data[1][c] + data[2][c] + data[3][c];
    } else if (c == 7)
        res = data[1][1] + data[2][2] + data[3][3];
    else
        res = data[1][3] + data[2][2] + data[3][1];

    res -= 6;
    printf("%d", resCheck[res]);

    return 0;
}
