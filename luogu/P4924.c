#include <stdio.h>

#define IVS_N 505

int matrix[IVS_N][IVS_N];
int newMatrix[IVS_N][IVS_N];

void ivsRotate(int ii, int ij, int ir, int id) {
    int len = 2 * ir + 1;
    int begI = ii - ir, begJ = ij - ir, endI = ii + ir, endJ = ij + ir;

    if (id == 0)
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j)
                newMatrix[begI + j][endJ - i] = matrix[begI + i][begJ + j];
    else
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j)
                newMatrix[endI - j][begJ + i] = matrix[begI + i][begJ + j];

    for (int i = begI; i <= endI; ++i)
        for (int j = begJ; j <= endJ; ++j)
            matrix[i][j] = newMatrix[i][j];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int v = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            matrix[i][j] = v;
            ++v;
        }

    int a, b, c, d;
    while ((scanf("%d%d%d%d", &a, &b, &c, &d)) != EOF)
        ivsRotate(a, b, c, d);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            printf("%d ", matrix[i][j]);
        putchar('\n');
    }

    return 0;
}
