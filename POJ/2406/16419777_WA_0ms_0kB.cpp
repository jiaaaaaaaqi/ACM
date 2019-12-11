//42704K    2829MS    C++    2709B    2013-12-18 13:31:43
/*

    题意：
        给出一个由某个子串重复R次组成的字符串，求R的最大值
    
    后缀数组：
        KMP应该会简单些，因为此处要练习后缀数组，故用后缀数组。首先考虑用DA的话会TLE，
    因为其时间复杂度为O(nlgn)，数据太大(n=2000000)。
        此处用dc3，dc3的算法没研究，只是套用其模板，dc3算法会比DA快些，在此处勉勉强强
    的过了。先用dc3求出后缀数组，然后再求height数组，再穷举字符串长度len。求k能整除len 
    且suffix(1) 与 suffix(k+1) 最长前缀等于len-k。
        在求最长公共前缀时，由于suffix(1)是固定的，利用height数组的特性，求出height数组
    中每一个数到height[rank[0]]间的最小值即可。  
 
*/
#include<stdio.h>
#include<string.h>
#define N 2000005
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[N],wb[N],wv[N],ws[N];
int rank[N],height[N];    
int sa[N],r[N];
char c[N];
int lcp[N]; //记录到height[rank[0]]的最小值 
int Max(int a,int b)
{
    return a>b?a:b;
} 
int Min(int a,int b)
{
    return a<b?a:b;
}
int cmp(int *y,int a,int b,int l)
{
    return y[a]==y[b]&&y[a+l]==y[b+l];   
}

int c0(int *y,int a,int b)
{
    return y[a]==y[b]&&y[a+1]==y[b+1]&&y[a+2]==y[b+2];
}
int c12(int k,int *y,int a,int b)
{
    if(k==2) return y[a]<y[b]||y[a]==y[b]&&c12(1,y,a+1,b+1);
    else return y[a]<y[b]||y[a]==y[b]&&wv[a+1]<wv[b+1];
}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0;i<n;i++) wv[i]=r[a[i]];
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[wv[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
    return;
}
void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
        else for(i=0;i<tbc;i++) san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0;i<ta && j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
    return;
}
void get_height(int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return; 
}
int main(void)
{
    while(scanf("%s",c)!=EOF)
    {
        if(strcmp(c,".")==0) break;
        int n=strlen(c);
        for(int i=0;i<n;i++)
            r[i]=c[i]+1;
        r[n]=0;
        dc3(r,sa,n+1,256);
        get_height(n);
        //for(int i=0;i<n;i++) printf("%d %d %d\n",i,rank[i],height[i]);
        memset(lcp,0,sizeof(lcp));
        lcp[rank[0]]=N;
        for(int i=rank[0]-1;i>=0;i--) lcp[i]=Min(lcp[i+1],height[i+1]);
        for(int i=rank[0]+1;i<=n;i++) lcp[i]=Min(lcp[i-1],height[i]);
        //for(int i=0;i<=n;i++) printf("%d %d %d\n",rank[i],height[i],lcp[i]);
        for(int k=1;k<=n;k++)  //遍历所有值 
            if(n%k==0 && lcp[rank[k]]==n-k){
                printf("%d\n",n/k);
                break;
            }
    }
    return 0;
}
/*
abcd
aaaa
ababab
*/