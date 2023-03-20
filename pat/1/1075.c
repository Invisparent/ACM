#include <stdio.h>
#include <string.h>

char str[7];

int main() {
    gets(str);
    int len = (int) strlen(str);

    if (len == 6) {
        for (int t = 0; t < 4; ++t)
            putchar(str[t]);
        putchar('-');
        putchar(str[4]);
        putchar(str[5]);
    } else {
        int dig = 10 * str[0] + str[1] - 11 * '0';
        if (dig < 22)
            printf("20%c%c-", str[0], str[1]);
        else
            printf("19%c%c-", str[0], str[1]);
        putchar(str[2]);
        putchar(str[3]);
    }

    return 0;
}
