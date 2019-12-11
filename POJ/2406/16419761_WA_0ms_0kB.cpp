#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 2000005
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[N],wb[N],wv[N],ws[N];
int rank[N],height[N];
int sa[N],r[N];
char c[N];
int s[N];
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
void get_height(int *r,int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}

int rm[N];
int sss[N];
char arr[N];

int main()
{
    while(~scanf("%s",arr))
    {
//        memset(rm,0,sizeof(rm));
//        memset(height,0,sizeof(height));
        int len=strlen(arr);
        if(len==1 && arr[0]=='.') break;

        for(int i=0;i<len;i++) r[i]=r[i]+1;
        r[len]=0;

        dc3(r,sa,len+1,256);
        get_height(r,len);

        int temp=height[rank[0]];

        for(int i=rank[0]-1;i>=1;i--)
       {
            rm[i]=temp;
            temp=min(temp,height[i]);
            //cout<<rm[i]<<endl;
        }

        temp=0x3f3f3f3f;
        for(int i=rank[0]+1;i<=len;i++)
        {
            temp=min(temp,height[i]);
            rm[i]=temp;
           //cout<<rm[i]<<endl;
        }


        int ans=1;
        for(int i=1;i<=len;i++)
        {
            if(len%i!=0) continue;
            else
            {
                if(rm[rank[i]]==len-i)
                {
                    ans=len/i;
                    break;
                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
