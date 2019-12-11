#include<stdio.h>
#include<string.h>
struct node{
	int cur;
	int cnt;
};
node que[10005];
int ispri[10005]={0};
int vis[10005]={0};
int ans;
int begin,end;
void getpri()
{
	memset(ispri, 1, sizeof(ispri));
	ispri[0]=ispri[1]=0;
	for(int i=2; i<10000; i++)
		if(ispri[i])
			for(int j=2; i*j<10000; j++)
				ispri[i*j]=0;
}
void bfs()
{	
	if(end==begin)
	{
		ans=0;
		return ;
	}
	int head=0;
	int rear=1;
	que[0].cnt=0;
	que[0].cur=begin;
	vis[begin]=1;
	while(head<rear)
	{
		int num[5];
		num[1]=que[head].cur/1000;
		num[2]=que[head].cur/100%10;
		num[3]=que[head].cur/10%10;
		num[4]=que[head].cur%10;
		for(int i=1; i<5; i++)
		{
			for(int j=0; j<10; j++)
			{
				if(i==1&&j==0)
					continue;
				int newa;
				if(i==1)
					newa=j*1000+num[2]*100+num[3]*10+num[4];
				if(i==2)
					newa=j*100+num[1]*1000+num[3]*10+num[4];
				if(i==3)
					newa=j*10+num[1]*1000+num[2]*100+num[4];
				if(i==4)
				 	newa=j+num[2]*100+num[3]*10+num[1]*1000;
				if(vis[newa]||(!ispri[newa]))
					continue;
				que[rear].cur=newa;
				que[rear].cnt=que[head].cnt+1;
				vis[newa]=1;
				if(newa==end)
				{
					ans=que[rear].cnt;
					return ;
				}
				rear++;
			}
		}
		head++;
	}
}
int main()
{
	int T;
	getpri();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&begin, &end);
		ans=-1;
		memset(vis, 0, sizeof(vis));
		bfs();
		if(ans==-1)
			printf("Impossible.\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}