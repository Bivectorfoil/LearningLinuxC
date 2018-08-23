#include <stdio.h>

int countbin(unsigned int x) {
        /* 统计一个无符号整数的二进制表示中1的个数 */
        int i = 31, count = 0;
        for (; i>-1; --i)
                if (((x>>i)&1)==1)
                        ++count;
        return count;
}

int main(void) {
        int c;
        c = countbin(0b10101011);
        printf("%d\n", c);
        return 0;
}
