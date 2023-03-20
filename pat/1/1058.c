#include <stdio.h>

int main() {
    char ch;
    int sixCount;
    while ((ch = (char) getchar()) != EOF) {
        sixCount = 0;
        while (ch == '6') {
            ++sixCount;
            ch = (char) getchar();
        }

        if (sixCount) {
            if (sixCount > 9)
                printf("27");
            else if (sixCount > 3)
                putchar('9');
            else
                for (int t = 0; t < sixCount; ++t)
                    putchar('6');
        }

        putchar(ch);
    }

    return 0;
}
