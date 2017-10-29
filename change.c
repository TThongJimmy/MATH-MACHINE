/*数字转中文*/

/*
    LLX直接输入需要转换的一亿以内的正整数
    例子：
        MC_change(1234567)
        
    MC MathChinese
*/

long long MC_change(long long LLx)
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
    char DanWei[][3] = {"千","百","十","万","亿"};
    char Shu[][3] = {"零","一","二","三","四","五","六","七","八","九"};
    //char jieguo[50][3] = "";

    char gewei[10][2]  = {""};
    char yiwei[10][2]  = {""};
    char wanwei[10][2] = {""};

    int i, j, s;

    int ge  = LLx;
    int wan = LLx/array[0];
    int yi  = LLx/array[1];

    /*
        思路：
            因为我们中国人念数字不像外国一样三个三个一组，我们是四个四个一组
        (  一万,   一百万,       一亿,          十亿   )
          10000,  100 0000,  1 0000 0000,  10 0000 0000

            所以我用 “万” 和 “亿”，将数分开， “千” 和 “百” 在每个部分都会有
        分开后先按顺序输出 “亿位” 的数，再输出 “万位” 和 “个位”
    */
    s = 0;
    if(wan>0) s=1;    /**/
    if(yi >0) s=2;    /**/

    /* switch 只是选择从哪开始执行，执行完一个 case 会接着下一个*/
	switch(s)
    {
		case 2:
        {
            for(i=0; i<=1; i++)
            {
                yiwei[0][i] = Shu[(yi/1000)%10][i];
                yiwei[1][i] = DanWei[0][i];            /*千*/

                yiwei[2][i] = Shu[(yi/100)%10][i];
                yiwei[3][i] = DanWei[1][i];            /*百*/

                yiwei[4][i] = Shu[(yi/10)%10][i];
                yiwei[5][i] = DanWei[2][i];            /*十*/

                yiwei[6][i] = Shu[(yi/1)%10][i];
            }

            for(i=0; i<=6; i++)
            {
                printf("%c%c",yiwei[i][0],yiwei[i][1]);
            }
            printf("%c%c",DanWei[4][0],DanWei[4][1]);   /*输出 “亿” 这个字*/
        }

        case 1:
        {
            for(i=0; i<=1; i++)
            {
                wanwei[0][i] = Shu[(wan/1000)%10][i];
                wanwei[1][i] = DanWei[0][i];            /*千*/

                wanwei[2][i] = Shu[(wan/100)%10][i];
                wanwei[3][i] = DanWei[1][i];            /*百*/

                wanwei[4][i] = Shu[(wan/10)%10][i];
                wanwei[5][i] = DanWei[2][i];            /*十*/

                wanwei[6][i] = Shu[(wan/1)%10][i];
            }
            for(i=0; i<=6; i++)
            {
                printf("%c%c",wanwei[i][0],wanwei[i][1]);
            }
            printf("%c%c",DanWei[3][0],DanWei[3][1]);   /*输出 “万” 这个字*/
        }

        case 0:
        {
            for(i=0; i<=1; i++)
            {
                gewei[0][i] = Shu[(ge/1000)%10][i];
                gewei[1][i] = DanWei[0][i];            /*千*/

                gewei[2][i] = Shu[(ge/100)%10][i];
                gewei[3][i] = DanWei[1][i];            /*百*/

                gewei[4][i] = Shu[(ge/10)%10][i];
                gewei[5][i] = DanWei[2][i];            /*十*/

                gewei[6][i] = Shu[(ge/1)%10][i];
            }
            for(i=0; i<=6; i++)
            {
                printf("%c%c",gewei[i][0],gewei[i][1]);
            }
            /*个位不需要输出单位,但是需要换行*/
            printf("\n");
        }
    }


    return/**/;
}