#include <stdio.h>
#include <string.h>

int arr[4], d, offset, mp;

void swap(int *a, int *b) {
    int i = *a;
    *a = *b;
    *b = i;
}

void sort(int *ptr) {
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (ptr[i] > ptr[j])
                swap(ptr + i, ptr + j);
}

int check(int index) {
    if (arr[index] < d || arr[index] + offset < mp)
        return 0;
    return 1;
}

int main() {
    for (int t = 0; t < 4; ++t)
        scanf("%d", arr + t);
    scanf("%d %d", &d, &offset);

    int b[4];
    memcpy(b, arr, sizeof(b));
    sort(b);
    mp = b[3];

    int cnt = 0, pos;
    for (int t = 0; t < 4; ++t) {
        if (!check(t)) {
            ++cnt;
            pos = t;
        }
    }

    if (!cnt)
        printf("Normal");
    else if (cnt == 1)
        printf("Warning: please check #%d!", pos + 1);
    else
        printf("Warning: please check all the tires!");

    return 0;
}
