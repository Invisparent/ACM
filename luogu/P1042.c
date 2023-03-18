#include <stdio.h>
#include <stdlib.h>

#define IVS_N ((int) 26 * 2510)

int main() {
    char data[IVS_N];
    char ch = (char) getchar();
    int index = 0;
    while (ch != 'E') {
        // Data written in CRLF mode
        // And output in LF mode
        // ...
        //if (ch != '\n') {
        if (ch == 'W' || ch == 'L') {
            data[index] = ch;
            ++index;
        }
        ch = (char) getchar();
    }

    int w = 0, l = 0;
    for (int t = 0; t < index; ++t) {
        if (data[t] == 'W')
            ++w;
        else
            ++l;
        // ???
        //if (t % 11 == 0 && t) {
        // What the fuck
        if ((w >= 11 || l >= 11) && abs(w - l) > 1) {
            printf("%d:%d\n", w, l);
            w = 0;
            l = 0;
        }
    }
//    if (w || l)
    printf("%d:%d\n\n", w, l);
//    else
//        putchar('\n');

    w = 0, l = 0;
    for (int t = 0; t < index; ++t) {
        if (data[t] == 'W')
            ++w;
        else
            ++l;
        // ???
        //if (t % 21 == 0 && t) {
        if ((w >= 21 || l >= 21) && abs(w - l) > 1) {
            printf("%d:%d\n", w, l);
            w = 0;
            l = 0;
        }
    }
//    if (w || l)
    printf("%d:%d", w, l);

    return 0;
}
