#include <stdio.h>
#include <stdint.h>

#define IVS_LIM 100010

uint8_t nVisited[IVS_LIM];
uint8_t mVisited[IVS_LIM];

int main() {
    int n, m, q;
    scanf("%d %d %d\n", &n, &m, &q);
    long long sig = (long long) n * m;

    int a, b;
    for (int t = 0; t < q; ++t) {
        scanf("%d %d\n", &a, &b);
        if (a) {
            if (!nVisited[b]) {
                sig -= n;
                --m;
                nVisited[b] = 1;
            }
        } else if (!mVisited[b]) {
            sig -= m;
            --n;
            mVisited[b] = 1;
        }
    }

    printf("%lld", sig);

    return 0;
}
