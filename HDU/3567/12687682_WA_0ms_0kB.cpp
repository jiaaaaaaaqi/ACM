#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node{
	int pre[10];
	int n;
};
struct Node{
	int cnt;
	char way;
};
int numx,numx_;
Node path[380000];
int vis1[380000];
int vis2[380000];
int fac[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int dis[4]={1,-3,-1,3};
int str[10]={0};
int str_[10]={0};
char dir1[ ]="ruld";
char dir2[ ]="ldru";
int countstep1=0;
int countstep2=0;
char step1[1000000]={0};
char step2[1000000]={0}; 

int cantuo(int a[])
{
	int ans=0;
	for(int i=0; i<9; i++)
	{
		int k=0;
		for(int j=i+1; j<9; j++)
			if(a[i]>a[j])
				k++;
		ans+=k*fac[8-i];
	}
	return ans;
}

void print(int x)
{
	if(path[x].cnt==-1)
		return ;
	print(path[x].cnt);
	printf("%c", path[x].way);
}
int judge(int x, int i)
{
	int num1=x/3;
	int num2=x%3;
	if(i==0&&(num2>1))
		return 0;
	if(i==1&&(num1<1))
		return 0;
	if(i==2&&(num2<1))
		return 0;
	if(i==3&&(num1>1))
		return 0;
	return 1;
}
void bfs()
{
	
	int count=2;
	queue<node> q1, q2;
	node p1, p2;
	for(int i=0; i<9; i++)
	{
		p1.pre[i]=str[i];
		p2.pre[i]=str_[i];
	}
	p1.n=numx;
	p2.n=numx_;

	q1.push(p1);
	q2.push(p2);
	
	vis1[cantuo(str)]=1;
	vis2[cantuo(str_)]=2;

	path[1].cnt=-1;
	path[2].cnt=-1;
		
	while(!q1.empty()&&!q2.empty())
	{
		node u=q1.front();
		q1.pop();
		int p=cantuo(u.pre);
		if(vis2[p])
		{
			int k=vis1[p];
			while(path[k].cnt!=-1)
			{
				step1[countstep1]=path[k].way;
				k=path[k].cnt;
				countstep1++;
			}
			k=vis2[p];
			while(path[k].cnt!=-1)
			{
				step2[countstep2]=path[k].way;
				k=path[k].cnt;
				countstep2++;
			}
			return ;
		}
		else
		{ 
			node u2;
			for(int i=0; i<4; i++)
			{
				u2=u;
				if (!judge(u.n, i))  
				 	continue;
				int newn=u.n+dis[i];
	
				u2.pre[u.n]=u2.pre[newn];
				u2.pre[newn]=0;
				u2.n=newn;
				int v=cantuo(u2.pre);
				if(vis1[v])
					continue;
				vis1[v]=++count;
				path[count].way=dir1[i];
				path[count].cnt=vis1[p];
				q1.push(u2);
			}
		}
		
		u=q2.front();
		q2.pop();
		p=cantuo(u.pre);
		if(vis1[p])
		{
			int k=vis1[p];
			while(path[k].cnt!=-1)
			{
				step1[countstep1]=path[k].way;
				k=path[k].cnt;
				countstep1++;
			}
			k=vis2[p];
			while(path[k].cnt!=-1)
			{
				step2[countstep2]=path[k].way;
				k=path[k].cnt;
				countstep2++;
			}
			return ;
		}
		else
		{
			node u2;
			for(int i=0; i<4; i++)
			{
				u2=u;
				if (!judge(u.n, i))  
				 	continue;
				int newn=u.n+dis[i];

				u2.pre[u.n]=u2.pre[newn];
				u2.pre[newn]=0;
				u2.n=newn;
				int v=cantuo(u2.pre);
				if(vis2[v])
					continue;
				vis2[v]=++count;
				path[count].way=dir2[i];
				path[count].cnt=vis2[p];
				q2.push(u2);
			}
		}
	}
}

int main()
{
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--)
	{
		char str1[10]={0};
		char str_1[10]={0};
		scanf("%s%s",str1, str_1); 
		for(int i=0; str1[i]!='\0'; i++)
		{
			if(str1[i]=='X')
			{
				numx=i;
				str[i]=0;
			}
			else
				str[i]=str1[i]-'0';
		}

		for(int i=0; str_1[i]!='\0'; i++)
		{
			if(str_1[i]=='X')
			{
				numx_=i;
				str_[i]=0;
			}
			else
				str_[i]=str_1[i]-'0';
		}

		countstep1=0;
		countstep2=0;

		bfs();
		printf("Case %d: %d\n", cas++, countstep1+countstep2);
		for(int i=countstep1-1; i>=0; i--)
			printf("%c", step1[i]);
		printf("%s", step2);		
		printf("\n");

		memset(str, 0, sizeof(str));
		memset(str_, 0, sizeof(str_));
		memset(step1, 0, sizeof(step1));
		memset(step2, 0, sizeof(step2));
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		memset(path, 0, sizeof(path));
	}
	return 0;
} 