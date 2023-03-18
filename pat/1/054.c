#include <stdio.h>
#include <stdint.h>

#define IVS_LIM 1005

char data[IVS_LIM][IVS_LIM];

int xread() {
    int retVal = 0;
    char ch = (char) getchar();

    while (ch < '0' || ch > '9')
        ch = (char) getchar();

    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 1) + (retVal << 3) + ch - '0';
        ch = (char) getchar();
    }

    return retVal;
}

int main() {
    char r = (char) getchar();
    getchar();
    int n = xread();

    for (int t = 1; t <= n; ++t)
        gets(data[t] + 1);

    uint8_t same = 1;
    for (int i = 1; i <= n / 2; ++i)
        for (int j = 1; j <= n; ++j)
            if (data[i][j] != data[n - i + 1][n - j + 1]) {
                same = 0;
                break;
            }

    if (same)
        printf("bu yong dao le\n");

    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j)
            if (data[i][j] != ' ')
                putchar(r);
            else
                putchar(' ');
        putchar('\n');
    }

    return 0;
}
