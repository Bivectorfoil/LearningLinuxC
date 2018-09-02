#include <stdio.h>

// test platform is big or little endian
union u {
        int n;
        unsigned char byte[4];
};

int main(void)
{
        union u a = { 0x2211 } ;
        printf("sizeof u = %lu\n", sizeof(a));
        printf("hex dump of u: %x %x %x %x \n",
                        a.byte[0], a.byte[1], a.byte[2], a.byte[3]);
        return 0;
}
