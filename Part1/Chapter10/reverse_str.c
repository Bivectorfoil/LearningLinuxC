#include <stdio.h>

int main(void)
{
        /* 输出倒序字符串 */
        /*输出结果不正确：
         * hello
         *
         */
        int i;
        char str[6] = "hello";
        char reverse_str[6] = "";

        printf("%s\n", str);
        for (i = 0; i < 5; i++)
                reverse_str[5-i] = str[i];
        printf("%s\n", reverse_str);
        return 0;
}

/* 问题出在reverse_str[5-i] = str[i]
 * 注意字符串str[6] = "hello\0"
 * reverse_str[5-i]将\0换到了前头
 * 应更正为reverse_str[4-i] = str[i];
 */
