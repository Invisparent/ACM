#include <stdio.h>

int cst;

int ivsPow2(int x) {
    if (!x)
        return 1;
    return 2 * ivsPow2(x - 1);
}

void solve() {
    int res = 1;
    char ch = (char) getchar();

    while (ch != '\n') {
        res = 2 * res + (ch == 'n');
        ch = (char) getchar();
    }

    printf("%d\n", res - cst);
}

int main() {
    int n, tt;
    scanf("%d %d\n", &n, &tt);
    cst = ivsPow2(n) - 1;

    while (tt--)
        solve();

    return 0;
}
