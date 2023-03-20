#include <stdio.h>

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

void solve() {
    int resA = 114514, resB = 114514;

    for (int t = 0; t < 3; ++t)
        resA += getchar();

    for (int t = 0; t < 3; ++t)
        resB += getchar();

    if (resA == resB)
        printf("You are lucky!\n");
    else
        printf("Wish you good luck.\n");

    getchar();
}

int main() {
    int tt = xread();

    while (tt--)
        solve();

    return 0;
}
