#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 1000009;
int a[maxn],b[maxn],d2[maxn],ans,d[maxn],n,fx[4]={1,0,-1};

int main() {
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i!=0) d[i]=a[i]-a[i-1];
		}
		ans=9999999;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				int st=a[0]+fx[i],ed=a[n-1]+fx[j],cha=ed-st;
				if(cha%(n-1)==0)
				{
					int dc=cha/(n-1),tmp=0;
					//bool vis[maxn]={0};
					memcpy(b,a,sizeof(b));
					memcpy(d2,d,sizeof(d2));
					if(abs(abs((b[1]-st))-abs(dc))>1)continue;
					if(abs(abs((ed-b[n-2]))-abs(dc))>1)continue;
					//printf("* %d %d\n",st,ed);
					//vis[0]=vis[n-1]=1;
					d2[1]=b[1]-st,d2[n-1]=ed-b[n-2];
					//printf("%d %d\n",d2[1],d2[n-1]);
					for(int q=1;q<n-1;q++)
					{
						if(d2[q]==dc) continue;
						if(d2[q]-1==dc)
						{
							b[q]--;
							d2[q+1]++;
						}
						else if(d2[q]+1==dc)
						{
							b[q]++;
							d2[q+1]--;
						}
						else
						{
							tmp=-1;
							break;
						}
						tmp++;
					 }
					//if(st==0)
					/* for(int q=0;q<n;q++)
						printf("%d ",b[q]);
						puts("");*/	
					 if(tmp==-1) continue;
					 //printf("tmp = %d\n",tmp);
					if(i!=1) tmp++;
					if(j!=1) tmp++; 
					if(d2[n-1]==dc) ans=min(tmp,ans);
				}
			}
			if(ans!=9999999)
				printf("%d\n",ans);
			else
				printf("-1\n");
	}	
}
