// What the fuck?

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define IVS_LIM 505

const char dstA[] = "qiandao", dstB[] = "easy";

char str[IVS_LIM];

int n, m;

int xread() {
    int retVal = 0;
    char ch = (char) getchar();

    while (ch < '0' || ch > '9')
        ch = (char) getchar();

    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 1) + (retVal << 3) + ch - '0';
        ch = (char) getchar();
    }

    return retVal;
}

uint8_t strFind(const char *srcBeg, const char *srcEnd, const char *dstBeg, const char *dstEnd) {
    while (srcBeg < srcEnd) {
        const char *ptrA = srcBeg;
        const char *ptrB = dstBeg;
        while (ptrA < srcEnd && ptrB < dstEnd && *ptrA == *ptrB) {
            ++ptrA;
            ++ptrB;
        }
        if (ptrB == dstEnd)
            return 1;

        ++srcBeg;
    }

    return 0;
}

int main() {
    n = xread();
    m = xread();

//    if (m >= n) {
//        puts("Wo AK le");
//        return 0;
//    }

    if (!m) {
        for (int t = 0; t < n; ++t) {
            gets(str);
            uint8_t resA = strFind(str, str + strlen(str), dstA, dstA + strlen(dstA));
            uint8_t resB = strFind(str, str + strlen(str), dstB, dstB + strlen(dstB));

            if (!resA && !resB) {
                puts(str);
                return 0;
            }
        }

        puts("Wo AK le");
        return 0;
    }

    for (int t = 0; t < n; ++t) {
        gets(str);
        if (!m) {
            puts(str);
            return 0;
        }

        uint8_t resA = strFind(str, str + strlen(str), dstA, dstA + strlen(dstA));
        uint8_t resB = strFind(str, str + strlen(str), dstB, dstB + strlen(dstB));

        if (!resA && !resB)
            --m;
    }

    puts("Wo AK le");

    return 0;
}
