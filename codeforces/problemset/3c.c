#include <stdio.h>
#include <stdint.h>

char data[5][5];

uint8_t check(const char ch) {
    for (int t = 1; t <= 3; ++t)
        if ((data[1][t] == ch && data[1][t] == data[2][t] && data[2][t] == data[3][t]) ||
            (data[t][1] == ch && data[t][1] == data[t][2] && data[t][2] == data[t][3]))
            return 1;

    if (data[1][1] == ch && data[1][1] == data[2][2] && data[2][2] == data[3][3])
        return 1;

    if (data[1][3] == ch && data[1][3] == data[2][2] && data[2][2] == data[3][1])
        return 1;

    return 0;
}

int main() {
    int sa = 0, sb = 0;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            data[i][j] = (char) getchar();
            if (data[i][j] == 'X')
                ++sa;

            // ZERO!!! NOT 'O'!!!
            else if (data[i][j] == '0')
                ++sb;
        }
        getchar();
    }

    if (sa - sb > 1 || sb > sa) {
        printf("illegal");
        return 0;
    }

    uint8_t resA = check('X');
    uint8_t resB = check('0');

    if (resA == 1 && resB == 1)
        printf("illegal");
    else if (resA) {
        if (sa == sb + 1)
            printf("the first player won");
        else
            printf("illegal");
    } else if (resB) {
        if (sa == sb)
            printf("the second player won");
        else
            printf("illegal");
    } else if (sa + sb == 9)
        printf("draw");
    else if (sa == sb)
        printf("first");
    else
        printf("second");

    return 0;
}
