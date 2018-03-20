#include <stdio.h>

double mypow(double x, int n)
{
        /* 循环实现指数计算，具体解释可参照下列链接：
         * https://stackoverflow.com/questions/25571377/\
         * iterative-implementation-of-powx-n
         */
        double left = x;
        double right = 1;

        while (n > 1) {
                if (n % 2 == 1)
                        right *= left;
                left = left * left;
                n = n / 2;
        }
        return left * right;
}

/*
double mypow(double x, int n)
{
        // 递归实现
        double val;
        int i = 0;
        while (i <= n) {
                if (n % 2 == 0) {
                        val = val * val;
                } else {
                        val = val * val * x;
                }

        return val;
}
*/

int main(void)
{
        printf("%f\n", mypow(3, 5));
        return 0;
}
