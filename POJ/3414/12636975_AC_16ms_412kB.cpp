#include<stdio.h>
#include<string.h>
struct node{
	int x,y;
	int cnt;
	int front;
	int way;
};
node que[1000000];
int vis[110][110]={0};
int a,b,c;
int ans;
int head;
int rear;
void bfs()
{
	head=0;
	rear=1;
	vis[0][0]=1;
	que[0].x=0,	que[0].y=0, que[0].cnt=0, que[0].front=-1;
	while(head<rear)
	{
		for(int i=1; i<=6; i++)
		{
			int num;
			int newa=que[head].x;
			int newb=que[head].y;
			if(i==1)
				newa=a;
			if(i==2)
				newb=b;
			if(i==3)
				newa=0;
			if(i==4)
				newb=0;
			if(i==5)
			{
				num=b-newb;
				if(num>newa)
				{
					newb+=newa;
					newa=0;
				}
				else
				{
					newb=b;
					newa-=num;
				}
			}
			if(i==6)
			{
				num=a-newa;
				if(num>newb)
				{
					newa+=newb;
					newb=0;
				}
				else
				{
					newa=a;
					newb-=num;
				}
			}
			if(vis[newa][newb])
				continue;
			que[rear].x=newa;
			que[rear].y=newb;
			que[rear].front=head;
			que[rear].cnt=que[head].cnt+1;
			que[rear].way=i;
			vis[newa][newb]=1;
			if(newa==c||newb==c)
			{
				ans=que[rear].cnt;
				return ;
			}
			rear++;
		}
		head++;
	}
}
void print(int n)
{
	if(que[n].front==-1)
		return ;
	print(que[n].front);
	int x=que[n].way;
	if(x==1)
		printf("FILL(1)\n");
	if(x==2)
		printf("FILL(2)\n");
	if(x==3)
		printf("DROP(1)\n");
	if(x==4)
		printf("DROP(2)\n");
	if(x==5)
		printf("POUR(1,2)\n");
	if(x==6)
		printf("POUR(2,1)\n");
}
int main()
{
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		ans=-1;
		memset(vis, 0, sizeof(vis));
		bfs();
		if(ans==-1)
			printf("impossible\n");
		else
		{
			printf("%d\n",ans);
			print(rear);
/*			printf("%d\n",rear);
			for(int i=0; i<15; i++)
				printf("%d  %d\n",que[i].front, que[i].way);
*/		}
	}
	return 0;
}