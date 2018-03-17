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

/* 第k小的元素在start和end之间， 找出并返回该元素 */
int order_statistic(int start, int end, int k)
{
        int i;
        /* 用partition函数把序列分成两部分，中间的pivot元素是序列中的第i个 */
        i = partition(start, end);
        if (k == i+1)
                return a[i];
        /* 第k小的元素在序列后半部分 */
        else if (k > i)
                order_statistic(i+1, end, k);
        /* 第k小的元素在序列前半部分 */
        else
                order_statistic(start, i-1, k);
}

int main(void)
{
        int k = 3;
        printf("第%d 小的元素为：%d\n", k, order_statistic(0, LEN-1, k));
        return 0;
}
