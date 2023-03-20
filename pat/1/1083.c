#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    char ca, cb;
    if (c >= a)
        ca = 'Y';
    else
        ca = 'N';
    if (d >= a)
        cb = 'Y';
    else
        cb = 'N';
    if (c >= b || d >= b) {
        ca = 'Y';
        cb = 'Y';
    }
    printf("%d-%c %d-%c\n", c, ca, d, cb);

    if (c >= a && d >= a)
        printf("huan ying ru guan");
    else if (c < a && d < a)
        printf("zhang da zai lai ba");
    else if (c < b && d < b)
        if (c >= a)
            printf("1: huan ying ru guan");
        else
            printf("2: huan ying ru guan");
    else {
        if (c <= a)
            printf("qing 2 zhao gu hao 1");
        else
            printf("qing 1 zhao gu hao 2");
    }

    return 0;

}
