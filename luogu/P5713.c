#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n * 2 <= 10)
        printf("Local");
    else
        printf("Luogu");
    return 0;
}
