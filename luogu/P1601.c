// Don't forget 0 + 0
// ...

#include <stdio.h>
#include <string.h>

#define IVS_N 505

char a[IVS_N], b[IVS_N];
char res[IVS_N];

int digA, digB;

int main() {
    memset(a, '0', sizeof(a));
    memset(b, '0', sizeof(b));
    memset(res, '0', sizeof(res));

//    char ch = (char) getchar();
//    while (ch != '\n') {
//        a[digA] = ch;
//        ++digA;
//        ch = (char) getchar();
//    }
//
//    while (scanf("%c", &ch) != EOF) {
//        b[digB] = ch;
//        ++digB;
//    }
    scanf("%s\n%s", a, b);

    digA = (int) strlen(a) - 1;
    digB = (int) strlen(b) - 1;

    for (int t = IVS_N - 1; t >= 0; --t) {
        if (digA >= 0) {
            res[t] += a[digA] - '0';
            --digA;
        }
        if (digB >= 0) {
            res[t] += b[digB] - '0';
            --digB;
        }
        if (res[t] > '9') {
            res[t] -= 10;
            ++res[t - 1];
        }
    }

    int beg = 0;
    // ??????????????????????????????????????????????
    //while (res[beg] == '0' && beg < IVS_N)
    while (beg < IVS_N && res[beg] == '0')
        ++beg;
    if (beg == IVS_N) {
        putchar('0');
        return 0;
    }
    while (beg < IVS_N) {
        putchar(res[beg]);
        ++beg;
    }

    return 0;
}
