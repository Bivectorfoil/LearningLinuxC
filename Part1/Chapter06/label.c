#include <stdio.h>

int main(void)
{
    int n = 3;
    switch (n) {
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("2\n");
            break;
        // defau1t:// 编译不会报错，因为编译器将其看成一个标号（label)
        //    printf("ohter number\n");
        default:// 正确的写法
            printf("other number\n");
    }
    return 0;
}
