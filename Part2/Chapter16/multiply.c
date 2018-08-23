#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y) {
        int i = 31, sum = 0;
        for (; i>-1; --i)
                if ((y>>i & 1) == 1)
                        sum = sum + (x<<i);
        return sum;
}

int main(void) {
        int sum;
        int x = 0b10110101;
        int y = 0b11011010;
        sum = multiply(x, y);
        printf("x * y = %x(by hex)\n", sum);
        printf("x * y = %d(by dec)\n", sum);
        return 0;
}
