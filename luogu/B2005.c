#include <stdio.h>

void printTriangle(char ch) {
    printf("  %c  \n %c%c%c \n%c%c%c%c%c", ch, ch, ch, ch, ch, ch, ch, ch, ch);
}

int main() {
    printTriangle((char) getchar());
    return 0;
}
