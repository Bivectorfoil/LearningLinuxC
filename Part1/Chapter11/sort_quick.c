#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 7, 1, 4, 9, 3, 2, 6 };

void swap(int *prev, int *after)
{
        int temp;
        temp = *prev;
        *prev = *after;
        *after = temp;
        return;
}

int partition(int start, int end)
{
        int i;
        int sortindex = start;

        for (i = start; i <= end; i++) {
                if (a[i] < a[end]) {
                        swap(&a[i], &a[sortindex]);
                        sortindex++;
                }
        }
        swap(&a[sortindex], &a[end]);
        return sortindex;
}

void quicksort(int start, int end)
{
        int mid;
        if (end > start) {
                mid = partition(start, end);
                quicksort(start, mid-1);
                quicksort(mid+1, end);
        }
}

int main(void)
{
        quicksort(0, LEN - 1);
        return 0;
}
