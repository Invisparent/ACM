#include <stdio.h>

int data[24];

int main() {
    for (int t = 0; t < 24; ++t)
        scanf("%d", &data[t]);

    int q;
    scanf("%d", &q);
    while (q >= 0 && q <= 23) {
        if (data[q] > 50)
            printf("%d Yes\n", data[q]);
        else
            printf("%d No\n", data[q]);
        scanf("%d", &q);
    }

    return 0;
}
