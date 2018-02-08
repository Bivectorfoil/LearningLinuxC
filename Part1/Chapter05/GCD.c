#include <stdio.h>

int GCD(int a, int b)
{
    // 辗转相除法求最大公约数, 递归式方法
    if (a % b == 0)
    {
        printf("The greatest common divisor is %d\n", b);
    } else {
        GCD(b, a % b);
    }
    return 0;
}

int main(void)
{
    int a = 102;
    int b = 170;
    GCD(a, b);
    return 0;
}
