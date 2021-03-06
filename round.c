/* 四舍五入 */

/*
    Fx为需要四舍五入的数，Fy为需要四舍五入到小数点前后几位
    例: F_round(3.1415926,0.3);  意思为：将“3.1415926”四舍五入到小数点后3位
        F_round(3141592.6,3.0);  意思为：将“3141592.6”四舍五入到小数点前3位
*/

/*
    bug!!!
        小数点后只能到6位
        原因：暂时未知
            2019/10/29
*/
double D_round(double Dx, double Dy)
{
    /*小心数组越界，如果报错是在 “ near array ” 这样就是数组越界*/
    long long  array[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000}; /*int类型 范围最大值：2147483647*/

    //这里还要判断一个边界，防止数据越界
    if(Dy > 0)
    {
        /*需要四舍五入到个位*/
        if (Dy == 1)
        {
            int Ix = (int)(Dx + 0.5);   /*第一位小数加0.5后进位的话代表大于等于5，再强制转换为int类型*/
            return Ix;
        }

        /*需要四舍五入的位大于个位*/
        else if(Dy > 1)
        {
            /* 思路：
                    由于需要四舍五入的数大于0,所以四舍五入后必然没有小数点，我们就可以直接把双精度浮点型直接转换成
                    整形的变量(而且浮点型变量无法取余)。
            */
            int Ix = Dx;
            int Iy = Dy;
            //int b = array[Iy-1];
            int c = (Ix-(Ix%array[Iy-2]))/array[Iy-2];       /*例：31415926-(26)/100 = 31415900/100 = 314159  */

            /* 思路：
                    截取数字的时候截取到需要判断的那一位 （ 例：四舍五入到百位需要判断十位的大小，我就截取到十位）
                    判断完后如果需要“五入”就在需要加1的地方加1
            */
            if(c%10 >=5)
                c=(c+10)/10;
            
            c = c*array[Iy-1];

            return c;
        }
        /*需要四舍五入的位在小数点之后*/
        else if(Dy < 1)
        {
            int         Iy = (int)(Dy*10);
            double      b = array[Iy];
            long long   d = (long long)(Dx*array[Iy+1]);    /*这个步骤是要把多余的数直接截掉*/

            if(d % 10 >= 5)     /*判断前一位数是否需要“五入”，“四舍”不需要变动就不需要管了*/
                d=(d+10)/10;

            double c = d/b;     /*恢复正常小数点状态*/

            return c;
        }
    }
}
