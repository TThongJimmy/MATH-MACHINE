/*数字转中文*/

/*

*/

long int L_change(long int Lx)
{
    int wan, yi;
    int array[2] = {10000, 100000000};
    char DanWei[6] = {'个','十','百','千','万','亿'};
    char Shu[10] = {'零','一','二','三','四','五','六','七','八','九'};
    char jieguo[] = {0};

    int i, j;

    int wan = Lx/array[0];
    int yi  = Lx/array[1];

    for(i=1; i>=0; i--)
    {
        /*测试数据的长度，决定是否需要多次循环*/
        if(Lx/array[1] > 0 )
            i = 1;
        else if(Lx/array[0] > 0)
            i = 0;

        /**/
        


        

    }

    return/**/;
}