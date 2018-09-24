#include <stdio.h>

int main(void)
{
        // access 'r' in alpha by pointer pal or ppal
        char alpha[4][3][2] = {{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
                {{'g', 'h'}, {'i', 'j'}, {'k', 'l'}},
                {{'m', 'n'}, {'o', 'p'}, {'q', 'r'}},
                {{'s', 't'}, {'u', 'v'}, {'w', 'x'}}};

        char (*pal)[2] = &alpha[1][0];
        char (*ppal)[3][2] = &alpha[1];
        printf("alpha r: %c\n", pal[5][1]);
        printf("alpha r: %c\n", ppal[1][2][1]);
        return 0;
}
