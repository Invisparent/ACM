#include <stdio.h>

int main() {
    float f;
    int i;
    scanf("%f%d", &f, &i);
    printf("%.3f\n%d", f / (float) i, i * 2);
    return 0;
}
