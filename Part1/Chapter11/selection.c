#include <stdio.h>

#define LEN 5
int a[LEN] = { 10, 5, 2, 4, 7 };

void selection_sort(void)
{
        /* 选择排序，升序实现 */
        int i, j, key;
        for (i = 0; i < LEN; i++) {
                printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
                key = i;
                for (j = i + 1; j < LEN; j++) {
                        if (a[key] > a[j])
                                key = j;
                }
                int temp;
                temp = a[i];
                a[i] = a[key];
                a[key] = temp;
        }
        printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
}

int main(void)
{
        selection_sort();
        return 0;
}
