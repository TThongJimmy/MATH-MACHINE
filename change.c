/*

*/

long int L_change(long int Lx)
{
    int wan, yi;
    int arry[2] = {10000, 100000000};
    char DanWei[6] = {'个','十','百','千','万','亿'};
    char Shu[10] = {'零','一','二','三','四','五','六','七','八','九'};
    char jieguo[] = {0};

    int i, j;

    wan = Lx/arry[0];
    yi  = Lx/arry[1];

    for(i=1; i<=0; i--)
    {
        /*测试数据的长度，决定是否需要多次循环*/
        if(Lx/arry[1] > 0 )
            i = 1;
        else if(Lx/arry[0] > 0)
            i = 0;

        /**/
        


        

    }

    return/**/;
}