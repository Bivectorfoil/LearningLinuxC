#include <stdio.h>

int flag = 0;
/* int foo(int flag)
   {
// 非递归调用main()
int main(void);
if (flag <= 2) {
printf("main function has been called by foo!\n");
main();
}
return 0;
}

int main(void)
{
// printf("flag is %d\n", flag);
flag += 1; // 注意和下一个语句的顺序
foo(flag);
return 0;
}
*/

int main(void)
{
        // 递归地调用main()
        if (flag <= 2) {
                printf("main function has been called!\n");
                flag++;
                main();
        }
        return 0;
}
