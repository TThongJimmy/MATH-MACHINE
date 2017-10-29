#include <stdio.h>


double D_round(double Dx, double Dy);
long long MC_change(long long LLx);
int home();
int function();

int main()
{
    home();
    start:
    function();
    int s;
    scanf("%d",&s);
    if(s<1 || s>3)
    {
		printf("�Բ���������������!!\n\n");
        scanf("%*[^\n]%*c");
		goto start;
    }

    switch(s)
    {
        case 1:
        {
            double x, y;
            printf("\n����������Ҫ�������������");
            scanf("%lf",&x);
            printf("\n(С����ǰ x λ���� x.0, С����� x λ���� 0.x)");
            printf("\n����������Ҫ�������뵽��һλ��");
            scanf("%lf",&y);
            D_round(x,y);
            getch();
            goto start;
        }

        case 2:
        {
            long long x;
            printf("\n(ֻ���� һ�� ���ڵ�������)");
            printf("\n����������Ҫת��Ϊ���ĵ�����");
            scanf("%lld",&x);
            MC_change(x);
            getch();
            goto start;
        }

        case 3:break;
    }
    
    getch();
	return 0;
}

int home()
{
    puts(" -----------------------------------");
    puts("|                                   |");
    puts("|       ��ӭʹ�� Math_Machine       |");
    puts("|                                   |");
    puts(" -----------------------------------");
    printf("�������������");
    getch();
    system("cls");

   
   return; 
}

int function()
{  
    system("cls");
    puts(" ------------------------------");
    puts("|          1.��������          |");
    puts("|         2.����ת����         |");
    puts("|            3.�˳�            |");
    puts(" ------------------------------");
    printf("��������Ӧ����:");
	return;
}

/* �������� */
/*��ϸ�μ� round.h*/
double D_round(double Dx, double Dy)
{
    int array[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    if(Dy > 0)
    {
        if(Dy >= 1)
        {
            int Ix = Dx;
            int Iy = Dy;
            int c = (Ix-(Ix%array[Iy-2]))/array[Iy-2];
            if(c%10 >=5)
                c=(c+10)/10;
            c = c*array[Iy-1];
            return c;
        }
        else if(Dy < 1)
        {
            int   Iy = Dy*10;
            double b = array[Iy];
            int    d = Dx*array[Iy+1];
            if(d % 10 >= 5)
                d=(d+10)/10;
            double c = d/b;
            return c;
        }
    }
}

/*����ת����*/
/*��ϸ��� change.c*/
long long MC_change(long long LLx)
{
    long long array[2] = {10000LL, 100000000LL};
    char DanWei[][3] = {"ǧ","��","ʮ","��","��"};
    char Shu[][3] = {"��","һ","��","��","��","��","��","��","��","��"};
    char gewei[10][2]  = {""};
    char yiwei[10][2]  = {""};
    char wanwei[10][2] = {""};
    int i, j, s;
    int ge  = LLx;
    int wan = LLx/array[0];
    int yi  = LLx/array[1];
    s = 0;
    if(wan>0) s=1;
    if(yi >0) s=2;
	switch(s)
    {
		case 2:
        {
            for(i=0; i<=1; i++)
            {
                yiwei[0][i] = Shu[(yi/1000)%10][i];
                yiwei[1][i] = DanWei[0][i];
                yiwei[2][i] = Shu[(yi/100)%10][i];
                yiwei[3][i] = DanWei[1][i];
                yiwei[4][i] = Shu[(yi/10)%10][i];
                yiwei[5][i] = DanWei[2][i];
                yiwei[6][i] = Shu[(yi/1)%10][i];
            }
            for(i=0; i<=6; i++)
            {
                printf("%c%c",yiwei[i][0],yiwei[i][1]);
            }
            printf("%c%c",DanWei[4][0],DanWei[4][1]);
        }
        case 1:
        {
            for(i=0; i<=1; i++)
            {
                wanwei[0][i] = Shu[(wan/1000)%10][i];
                wanwei[1][i] = DanWei[0][i];
                wanwei[2][i] = Shu[(wan/100)%10][i];
                wanwei[3][i] = DanWei[1][i];
                wanwei[4][i] = Shu[(wan/10)%10][i];
                wanwei[5][i] = DanWei[2][i];
                wanwei[6][i] = Shu[(wan/1)%10][i];
            }
            for(i=0; i<=6; i++)
            {
                printf("%c%c",wanwei[i][0],wanwei[i][1]);
            }
            printf("%c%c",DanWei[3][0],DanWei[3][1]);
        }
        case 0:
        {
            for(i=0; i<=1; i++)
            {
                gewei[0][i] = Shu[(ge/1000)%10][i];
                gewei[1][i] = DanWei[0][i];
                gewei[2][i] = Shu[(ge/100)%10][i];
                gewei[3][i] = DanWei[1][i];
                gewei[4][i] = Shu[(ge/10)%10][i];
                gewei[5][i] = DanWei[2][i];
                gewei[6][i] = Shu[(ge/1)%10][i];
            }
            for(i=0; i<=6; i++)
            {
                printf("%c%c",gewei[i][0],gewei[i][1]);
            }
            printf("\n");
        }
    }
    return;
}
