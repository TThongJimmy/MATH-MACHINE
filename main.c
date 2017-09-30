#include <stdio.h>
#include "round.c"

int main(int argc, char *argv[])
{
    double x, y;
    while(1)
    {
        printf("请输入需要四舍五入的数字\n");
        scanf("%lf",&x);

        printf("请输入需要四舍五入到几位\n");
        scanf("%lf",&y);
        

        printf("%lf\n\n",D_round(x,y));
    }
    return 0;
}
