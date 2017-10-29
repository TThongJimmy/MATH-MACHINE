/*����ת����*/

/*
    LLXֱ��������Ҫת����һ�����ڵ�������
    ���ӣ�
        MC_change(1234567)
        
    MC MathChinese
*/

long long MC_change(long long LLx)
{
    /*���ݽ����ж�(���ɹ�)*/
    /*
    if(LLx > 100000000)
    {
        printf("�Բ����������ֵֻ��Ϊһ�����ڵ���������1~100000000��");
        fprintf(stderr,"�Բ����������ֵֻ��Ϊһ�����ڵ���������1~100000000��");
        return 1;
    }
    */

    long long array[2] = {10000LL, 100000000LL};
    char DanWei[][3] = {"ǧ","��","ʮ","��","��"};
    char Shu[][3] = {"��","һ","��","��","��","��","��","��","��","��"};
    //char jieguo[50][3] = "";

    char gewei[10][2]  = {""};
    char yiwei[10][2]  = {""};
    char wanwei[10][2] = {""};

    int i, j, s;

    int ge  = LLx;
    int wan = LLx/array[0];
    int yi  = LLx/array[1];

    /*
        ˼·��
            ��Ϊ�����й��������ֲ������һ����������һ�飬�������ĸ��ĸ�һ��
        (  һ��,   һ����,       һ��,          ʮ��   )
          10000,  100 0000,  1 0000 0000,  10 0000 0000

            �������� ���� �� ���ڡ��������ֿ��� ��ǧ�� �� ���١� ��ÿ�����ֶ�����
        �ֿ����Ȱ�˳����� ����λ�� ����������� ����λ�� �� ����λ��
    */
    s = 0;
    if(wan>0) s=1;    /**/
    if(yi >0) s=2;    /**/

    /* switch ֻ��ѡ����Ŀ�ʼִ�У�ִ����һ�� case �������һ��*/
	switch(s)
    {
		case 2:
        {
            for(i=0; i<=1; i++)
            {
                yiwei[0][i] = Shu[(yi/1000)%10][i];
                yiwei[1][i] = DanWei[0][i];            /*ǧ*/

                yiwei[2][i] = Shu[(yi/100)%10][i];
                yiwei[3][i] = DanWei[1][i];            /*��*/

                yiwei[4][i] = Shu[(yi/10)%10][i];
                yiwei[5][i] = DanWei[2][i];            /*ʮ*/

                yiwei[6][i] = Shu[(yi/1)%10][i];
            }

            for(i=0; i<=6; i++)
            {
                printf("%c%c",yiwei[i][0],yiwei[i][1]);
            }
            printf("%c%c",DanWei[4][0],DanWei[4][1]);   /*��� ���ڡ� �����*/
        }

        case 1:
        {
            for(i=0; i<=1; i++)
            {
                wanwei[0][i] = Shu[(wan/1000)%10][i];
                wanwei[1][i] = DanWei[0][i];            /*ǧ*/

                wanwei[2][i] = Shu[(wan/100)%10][i];
                wanwei[3][i] = DanWei[1][i];            /*��*/

                wanwei[4][i] = Shu[(wan/10)%10][i];
                wanwei[5][i] = DanWei[2][i];            /*ʮ*/

                wanwei[6][i] = Shu[(wan/1)%10][i];
            }
            for(i=0; i<=6; i++)
            {
                printf("%c%c",wanwei[i][0],wanwei[i][1]);
            }
            printf("%c%c",DanWei[3][0],DanWei[3][1]);   /*��� ���� �����*/
        }

        case 0:
        {
            for(i=0; i<=1; i++)
            {
                gewei[0][i] = Shu[(ge/1000)%10][i];
                gewei[1][i] = DanWei[0][i];            /*ǧ*/

                gewei[2][i] = Shu[(ge/100)%10][i];
                gewei[3][i] = DanWei[1][i];            /*��*/

                gewei[4][i] = Shu[(ge/10)%10][i];
                gewei[5][i] = DanWei[2][i];            /*ʮ*/

                gewei[6][i] = Shu[(ge/1)%10][i];
            }
            for(i=0; i<=6; i++)
            {
                printf("%c%c",gewei[i][0],gewei[i][1]);
            }
            /*��λ����Ҫ�����λ,������Ҫ����*/
            printf("\n");
        }
    }


    return/**/;
}