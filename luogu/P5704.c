#include <stdio.h>

int main() {
    char ch = (char) getchar();
    putchar(ch + 'A' - 'a');
    return 0;
}
