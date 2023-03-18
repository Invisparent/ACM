#include <stdio.h>

int ivsPow(int a, int n) {
    if (!n)
        return 1;
    return a * ivsPow(a, n - 1);
}

char str[7];

int main() {
    int l, n;
    scanf("%d %d", &l, &n);

    for (int t = 0; t < l; ++t)
        str[t] = 'a';
    str[l] = '\0';

    int p = ivsPow(26, l) - n;
    for (int t = 0; t < l; ++t) {
        int np = ivsPow(26, l - t - 1);
        str[t] += p / np;
        p -= (p / np) * np;
    }

    puts(str);

    return 0;
}
