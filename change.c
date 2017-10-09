/*数字转中文*/

/*

*/
#include <stdio.h>
long long LL_change(long long LLx)
{
    /*数据界限判断(不成功)*/
    /*
    if(LLx > 100000000)
    {
        printf("对不起，输入的数值只能为一亿以内的正整数‘1~100000000’");
        fprintf(stderr,"对不起，输入的数值只能为一亿以内的正整数‘1~100000000’");
        return 1;
    }
    */

    long long array[2] = {10000LL, 100000000LL};
    char DanWei[6] = {'十','百','千','万','亿'};
    wchar_t Shu[10] = {'零','一','二','三','四','五','六','七','八','九'};
    char jieguo[50] = "";

    int i, j;

    int wan = LLx/array[0];
    int yi  = LLx/array[1];

    s = 0;
    if(wan>0) s=1;    /**/
    if(yi >0) s=2;    /**/

	switch(s)
    {
		case 2:
        {
            /*  失败
            Y[1] = Shu[(wan/1000)%10];
            printf("Y= ");
            puts(Shu);
            */
            break;
        }
        case 1:break;
        case 0:break;
    }

    /*wprintf(L"%c%c  ----%d\n",Shu[7],Shu[8],(wan/1000)%10);*/

    return/**/;
}