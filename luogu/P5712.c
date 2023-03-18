#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("Today, I ate 1 apple.");
    else if (!n)
        printf("Today, I ate 0 apple.");
    else
        printf("Today, I ate %d apples.", n);
    return 0;
}
