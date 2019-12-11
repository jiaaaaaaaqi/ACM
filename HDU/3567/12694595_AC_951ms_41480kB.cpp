#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node{
	int x;
	char pre[10];
	int ct;
	int t;
};
struct path1{
	char way;
	int fath;
};
path1 path[10][370000];
int fac[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320};
char str1[10]={0};
char str2[10]={0};
int  dis[4]={3,-1,1,-3};
char dir[5]="dlru";
int time[10][370000];

int cantuo (char a[])
{
	int ans=0;
	for(int i=0; i<9; i++)
	{
		int k=0;
		for(int j=i+1; j<9; j++)
			if(a[j]<a[i])
				k++;
		ans+=k*fac[8-i];
	}
	return ans;
}

int check(int n, int i)
{
	int num1=n/3;
	int num2=n%3;
	if(i==0&&num1>1)
		return 0;
	if(i==1&&num2<1)
		return 0;
	if(i==2&&num2>1)
		return 0;
	if(i==3&&num1<1)
		return 0;
	return 1;
}

void bfs(char str[], int k)
{
	for(int i=0; i<370000; i++)
		path[k][i].fath=-1;

	queue<node> q;
	node cur,next;
	cur.ct=cantuo(str);
	cur.x =k;
	cur.t=0;
	strcpy(cur.pre, str);
	path[k][cantuo(str)].fath=-2;
	q.push(cur);
	
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			next=cur;
			if(check(cur.x, i))
			{
				int newn=cur.x+dis[i];
				next.pre[cur.x]=next.pre[newn];
				next.pre[newn]='0';
				next.x=newn;
				next.ct=cantuo(next.pre);
				if(path[k][next.ct].fath==-1)
				{
					path[k][next.ct].fath=cur.ct;
					path[k][next.ct].way=dir[i];
					next.t++;
					time[k][next.ct]=next.t;
					q.push(next);
				}
			}
		}
	}
}

void print(int k, int n)
{
	if(path[k][n].fath==-2)
		return ;
	print(k, path[k][n].fath);
	printf("%c", path[k][n].way);
}

void handle()
{
	bfs("012345678", 0);
	bfs("102345678", 1);
	bfs("120345678", 2);
	bfs("123045678", 3);
	bfs("123405678", 4);
	bfs("123450678", 5);
	bfs("123456078", 6);
	bfs("123456708", 7);
	bfs("123456780", 8);
}
int main ()
{
	handle ();
	int T;
	int cas=1;
	scanf("%d",&T);
	while (T--)
	{
		int k,j=1;
		int num[10]={0};
		scanf("%s%s", str1, str2);
		
		if(strcmp(str1, str2)==0)
		{
			printf("Case %d: 0\n\n",cas++);
			continue;
		}
		 
		for (int i=0; i<9; i++)
		{
			if (str1[i]=='X')
				k=i;
			else
				num[str1[i]-'0']=j++;
		}
		for (int i=0; i<9; i++)
		{
			if(str2[i]=='X')
				str2[i]='0'; 
			else
				str2[i]=num[str2[i]-'0']+'0';
		}
		int m=cantuo(str2);
		printf("Case %d: %d\n", cas++, time[k][m]);
		print(k, m);
		printf("\n");
	}
	return 0;
}
