#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// retVal: beforeEnd / Beg
int *partition(int *beg, int *end, int q) {
    int *retVal = beg, *travPtr = beg;
    while (travPtr != end) {
        if (*travPtr >= q)
            ++travPtr;
        else {
            swap(retVal, travPtr);
            ++retVal;
            ++travPtr;
        }
    }

    return retVal;
}

void quickSort(int *beg, int *end) {
    if (beg == end)
        return;
    int *divPtr = partition(beg, end, *beg);
    quickSort(beg, divPtr);
    quickSort(divPtr + 1, end);
}

int main() {
    int arr[6] = {1, 1, 4, 5, 1, 4};
    quickSort(arr, arr + sizeof(arr) / sizeof(int));
    for (int t = 0; t < 6; ++t)
        printf("%d ", arr[t]);

    return 0;
}
