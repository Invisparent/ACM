#include <stdio.h>

int om[6];
int data[6];

int main() {
    for (int t = 0; t < 6; ++t)
        scanf("%d", om + t);
    for (int t = 0; t < 6; ++t)
        data[t] = 6;

    int n;
    scanf("%d", &n);
    for (int t = 0; t < n; ++t) {
        for (int x = 0; x < 6; ++x)
            if (data[x] == om[x])
                --data[x];

        if (t != n - 1)
            for (int x = 0; x < 6; ++x)
                --data[x];
    }

    for (int x = 0; x < 6; ++x) {
        printf("%d", data[x]);
        if (x != 5)
            putchar(' ');
    }
    putchar('\n');

    return 0;
}
