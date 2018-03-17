#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 7, 10, 1, 9, 3, 2, 6 };

int search_min()
{
        /* 查找数组中最小值
         * 章节名：排序与查找；
         * 文件位置：线性查找；
         * 文件类型：习题1答案
         */
        int i, point;
        i = point = 0;

        while (i < LEN) {
                if (a[i] < a[point]) {
                        point = i;
                        printf("point is: %d\n", point);
                }
                i++;
        }
        return a[point];
}

int main(void)
{
        int min;
        min = search_min();
        printf("The min is: %d\n", min);
        return 0;
}
