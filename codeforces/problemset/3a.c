#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int abs(int x) {
    if (x < 0)
        return -x;
    else
        return x;
}

int main() {
    char a, b, c, d;
    scanf("%c%c\n%c%c", &a, &b, &c, &d);
    int diffX = c - a;
    int diffY = d - b;

    printf("%d\n", max(abs(diffX), abs(diffY)));

    while (diffX && diffY)
        if (diffX > 0 && diffY > 0) {
            printf("RU\n");
            --diffX;
            --diffY;
        } else if (diffX > 0) {
            printf("RD\n");
            --diffX;
            ++diffY;
        } else if (diffY > 0) {
            printf("LU\n");
            ++diffX;
            --diffY;
        } else {
            printf("LD\n");
            ++diffX;
            ++diffY;
        }

    while (diffX) {
        if (diffX > 0) {
            printf("R\n");
            --diffX;
        } else {
            printf("L\n");
            ++diffX;
        }
    }
    while (diffY) {
        if (diffY > 0) {
            printf("U\n");
            --diffY;
        } else {
            printf("D\n");
            ++diffY;
        }
    }

    return 0;
}
