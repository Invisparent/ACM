#include <stdio.h>
#include <stdlib.h>


#define IVS_N 3

int i32min(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int arr[IVS_N];
    for (int t = 0; t < IVS_N; ++t)
        scanf("%d", arr + t);
    qsort(arr, IVS_N, sizeof(arr[0]), i32min);
    for (int t = 0; t < IVS_N; ++t)
        printf("%d ", arr[t]);
    return 0;
}
