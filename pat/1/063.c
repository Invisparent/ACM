#include <stdio.h>

void boy(int h, int w) {
    if (h < 130)
        printf("duo chi yu! ");
    else if (h == 130)
        printf("wan mei! ");
    else
        printf("ni li hai! ");

    if (w < 27)
        printf("duo chi rou!\n");
    else if (w == 27)
        printf("wan mei!\n");
    else
        printf("shao chi rou!\n");
}

void girl(int h, int w) {
    if (h < 129)
        printf("duo chi yu! ");
    else if (h == 129)
        printf("wan mei! ");
    else
        printf("ni li hai! ");

    if (w < 25)
        printf("duo chi rou!\n");
    else if (w == 25)
        printf("wan mei!\n");
    else
        printf("shao chi rou!\n");
}

void solve() {
    int g, h, w;
    scanf("%d %d %d\n", &g, &h, &w);

    if (g)
        boy(h, w);
    else
        girl(h, w);
}

int main() {
    int tt;
    scanf("%d\n", &tt);

    while (tt--)
        solve();

    return 0;
}
