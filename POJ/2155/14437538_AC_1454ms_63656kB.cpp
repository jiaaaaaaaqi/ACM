#include<stdio.h>
#include<string.h>
 
#define xlson xl ,xmid ,xt << 1
#define xrson xmid+1 ,xr ,xt << 1 | 1
#define ylson yl ,ymid ,yt << 1
#define yrson ymid+1 ,yr ,yt << 1 | 1
#define N 1005
 
int cnt[N<<2][N<<2] ,n ,ans;
void UpdateY(int yl ,int yr ,int yt ,int c ,int d ,int xt)
{
    if(c <= yl && d >= yr)
    {
        cnt[xt][yt] ++;
        return ;
    }
    int ymid = (yl + yr) >> 1;
    if(c <= ymid) UpdateY(ylson ,c ,d ,xt);
    if(d > ymid) UpdateY(yrson ,c ,d ,xt);
    return ;
}
 
void UpdateX(int xl ,int xr ,int xt ,int a ,int b ,int c ,int d)
{
    if(a <= xl && b >= xr)
    {
        UpdateY(1 ,n ,1 ,c ,d ,xt);
        return ;
    }
    int xmid = (xl + xr) >> 1;
    if(a <= xmid) UpdateX(xlson ,a ,b ,c ,d);
    if(b > xmid) UpdateX(xrson ,a ,b ,c ,d);
    return ;
}
 
void QueryY(int yl ,int yr ,int yt ,int b ,int xt)
{
    ans += cnt[xt][yt];
    if(yl == yr) return ;
    int ymid = (yl + yr) >> 1;
    if(b <= ymid) QueryY(ylson ,b ,xt);
    else QueryY(yrson ,b ,xt);
    return ;
 
}
 
void QueryX(int xl ,int xr ,int xt ,int a ,int b)
{
    QueryY(1 ,n ,1 ,b ,xt);
    if(xl == xr) return ;
    int xmid = (xl + xr) >> 1;
    if(a <= xmid) QueryX(xlson ,a ,b);
    else QueryX(xrson ,a ,b);
    return ;
}
 
int main ()
{
    int t ,m ,i ,x1 ,y1 ,x2 ,y2;
    char str[5];
    scanf("%d" ,&t);
    while(t--)
    {
        scanf("%d %d" ,&n ,&m);
        memset(cnt ,0 ,sizeof(cnt));
        while(m--)
        {
            scanf("%s" ,str);
            if(str[0] == 'C')
            {
                scanf("%d %d %d %d" ,&x1 ,&y1 ,&x2 ,&y2);
                UpdateX(1 ,n ,1 ,x1 ,x2 ,y1 ,y2);
            }
            else
            {
                scanf("%d %d" ,&x1 ,&y1);
                ans = 0;
                QueryX(1 ,n ,1 ,x1 ,y1);
                if(ans % 2)
                printf("1\n");
                else printf("0\n");
            }
        }
        if(t) printf("\n");
    }
    return 0;
}
 
 
