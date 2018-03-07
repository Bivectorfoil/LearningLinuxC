#include <stdio.h>

int fib(int n)
{
        // 求fibnacci数列
        if (n <= 1)
        {
                return 1;
        } else {
                return fib(n-1) + fib(n-2);
        }
        return 0;
}

int main(void)
{
        int result;
        int n = 30;
        result = fib(n-1);
        printf("fib(%d) is %d\n", n, result);
        return 0;
}
