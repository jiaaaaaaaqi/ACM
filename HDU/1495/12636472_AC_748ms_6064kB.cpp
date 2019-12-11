#include<stdio.h>
#include<string.h>
struct node{
	int x,y,z;
	int cnt;
};
node que[1000005]={0};
int vis[105][105][105]={0};
int s,n,m;
int ans;
int check(int x, int y, int z)
{
	if(x==0&&y==z)
		return 1;
	if(y==0&&x==z)
		return 1;
	if(z==0&&x==y)
		return 1;
	return 0;
}
void bfs()
{
	int head=0;
	int rear=1;
	que[0].x=s,	que[0].y=0, que[0].z=0;
	que[0].cnt=0;
	vis[s][0][0]=1;
	while(head<rear)
	{
		for(int i=0; i<6; i++)
		{
			int numx=que[head].x;
			int numy=que[head].y;
			int numz=que[head].z;
			int num;
			if(i==0)
			{
				num=n-numy;
				if(num>numx)
				{
					numy+=numx;
					numx=0;
				}
				else
				{
					numy=n;
					numx-=num;
				}
			}
			if(i==1)
			{
				num=m-numz;
				if(num>numx)
				{
					numz+=numx;
					numx=0;
				}
				else
				{
					numz=m;
					numx-=num;
				}
			}
			if(i==2)
			{
				num=s-numx;
				if(num>numy)
				{
					numx+=numy;
					numy=0;
				}
				else
				{
					numx=s;
					numy-=num;
				}
			}
			if(i==3)
			{
				num=m-numz;
				if(num>numy)
				{
					numz+=numy;
					numy=0;
				}
				else
				{
					numz=m;
					numy-=num;
				}
			}
			if(i==4)
			{
				num=s-numx;
				if(num>numz)
				{
					numx+=numz;
					numz=0;
				}
				else
				{
					numx=s;
					numz-=num;
				}
			}
			if(i==5)
			{
				num=n-numy;
				if(num>numz)
				{
					numy+=numz;
					numz=0;
				}
				else
				{
					numy=n;
					numz-=num;
				}
			}
			if(numx<0||numx>s)
				continue;
			if(numy<0||numy>n)
				continue;
			if(numz<0||numz>m)
				continue;
			if(vis[numx][numy][numz])
				continue;
			que[rear].x=numx;
			que[rear].y=numy;
			que[rear].z=numz;
			que[rear].cnt=que[head].cnt+1;
			vis[numx][numy][numz]=1;
			if(check(numx, numy, numz))
			{
				ans=que[rear].cnt;
				return ;
			}
			rear++;
		}
		head++;
	}
}
int main()
{
	while(scanf("%d%d%d",&s,&n,&m),s||n||m)
	{
		ans=-1;
		memset(vis, 0, sizeof(vis));
		bfs();
		if(ans==-1)
			printf("NO\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}