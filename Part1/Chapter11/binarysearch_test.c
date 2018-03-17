#include <stdio.h>
#include <assert.h>

#define LEN 8
int a[LEN] = { 1, 2, 2, 2, 5, 6, 8, 9 };

int is_sort(void)
{
        /* Precondition */
        int i;
        for (i = 1; i < LEN; i++)
                if (a[i-1] > a[i])
                        return 0;
        return 1;
}

int mustbe(int start, int end, int number)
{
        /* 若待查找元素number存在与数组a中，
         * 则其一定在a[start..end]中
         */
        int i;
        for (i = 0; i < start; i++)
                if (a[i] == number)
                        return 0;
        for (i = end+1; i < LEN; i++)
                if (a[i] == number)
                        return 0;
        return 1;
}

int contains(int n)
{
        /* 待查找元素一定在数组a中 */
        int i;
        for (i = 0; i < LEN; i++)
                if (a[i] == n)
                        return 1;
        return 0;
        }

int binarysearch(int number)
{
        /* 二分查找
         * 附带一系列断言测试
         */
        int mid, start = 0, end = LEN - 1;

        assert(is_sort()); /* Precondition */
        while (start <= end) {
                assert(mustbe(start, end, number)); /* Maintenance */
                mid = (start + end) / 2;
                if (a[mid] < number)
                        start = mid + 1;
                else if (a[mid] > number)
                        end = mid - 1;
                else {
                        assert(mid >= start && mid <= end
                                        && a[mid] == number); /* Precondition */
                        return mid;
                }
        }
        assert(!contains(number)); /* Postcondition 2 */
        return -1;
}

int main(void)
{
        printf("%d\n", binarysearch(5));
        return 0;
}
