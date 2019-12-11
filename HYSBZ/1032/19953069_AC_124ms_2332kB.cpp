
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
struct node
{
    int num, color;
} ball[515];
int f[515][515]; //从i到j的最少使用次数
int a[515];
int m, n;
int main()
{
    while (~scanf("%d", &n))
    {
        m = 0;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        memset(f, 0x3f3f3f, sizeof(f));
        memset(ball, 0, sizeof(ball));
        int bal = a[1], num = 0;
        for (int i = 1; i <= n; i++) //预处理相同颜色的球,记录个数与颜色
        {
            if (a[i] != bal)
            {
                ball[++m].num = num;
                ball[m].color = bal;
                num = 1;
                bal = a[i];
            }
            else
                num++;
            if (i == n)
            {
                ball[++m].num = num;
                ball[m].color = bal;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (ball[i].num > 1)
            { //数量大于1则需要1个球，否则两个才能消
                f[i][i] = 1;
            }
            else
                f[i][i] = 2;
        }
        for (int p = 2; p <= m; p++)
        {
            for (int i = 1; i + p - 1 <= m; i++)
            {
                int j = i + p - 1;
                if (ball[i].color == ball[j].color)
                { //若区间两端颜色相同
                    if (ball[i].num + ball[j].num == 2)
                    {
                        f[i][j] = f[i + 1][j - 1] + 1;
                    }
                    else
                        f[i][j] = f[i + 1][j - 1];
                }
                for (int k = i; k < j; k++)
                {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                }
            }
        }
        printf("%d\n", f[1][m]);
    }
    return 0;
}
