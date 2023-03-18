#include <stdio.h>
#include <stdint.h>

#define IVS_N 105

const int ox[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int oy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

uint8_t data[IVS_N][IVS_N];

int xread() {
    int retVal = 0;
    char ch = (char) getchar();

    while (ch < '0' || ch > '9')
        ch = (char) getchar();

    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 3) + (retVal << 1) + ch - '0';
        ch = (char) getchar();
    }

    return retVal;
}

char getMine(const int n, const int m) {
    if (data[n][m])
        return '*';

    char retVal = '0';
    for (int t = 0; t < 8; ++t)
        if (data[n + ox[t]][m + oy[t]])
            ++retVal;
    return retVal;
}

int main() {
    int n = xread();
    int m = xread();

    char ch;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ch = (char) getchar();
            if (ch == '*')
                data[i][j] = 1;
        }
        getchar();
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            putchar(getMine(i, j));
        putchar('\n');
    }

    return 0;
}
