/* xassert.c _Assert function */
#include <stdio.h>
#include <stdlib.h>

void _Assert(char *mesg)
{   /* print assertion message an abort */
        fputs(mesg, stderr);
        fputs(" -- assertion failed\n", stderr);
        abort();
}
