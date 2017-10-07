#include <stdio.h>
#include "change.c"

int main(int argc, char *argv[])
{
    long a = 12345678910;
    L_change(a);
    puts(L_change(a));
    printf("%s",L_change(a));
    return 0;
}
