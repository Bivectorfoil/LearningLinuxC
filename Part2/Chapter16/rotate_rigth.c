#include <stdio.h>

unsigned int rotate_rigth(unsigned int x) {
        int length = 32;
        int n = 8;
        x = (x>>n) | (x<<(length-n));
        return x;
}

int main(void) {
        unsigned int x = 0xdeadbeef;
        printf("old: %x\n", x);
        x = rotate_rigth(x);
        printf("new: %x\n", x);
}
