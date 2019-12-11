#include<stdio.h>
#include<string.h>
struct Node{
	char way;
	int father;
};
Node path[370000]={0};
struct node{
	int pre[10];
	int son;
	int n;
};
node que[370000]={0};
int fac[11]={1 , 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int kangtuo(int a[])
{
	int ans=0;
	for(int i=0; i<9; i++)
	{
		int k=0;
		for(int j=i+1; j<9; j++)
			if(a[j]>a[i])
				k++;
		ans+=k*fac[8-i];
	}
	return ans;
}
void bfs(int a[])
{
	int head=0;
	int rear=1;
	for(int i=0; i<9; i++)
		que[0].pre[i]=a[i];
	que[0].n=8,que[0].son=0;
	path[0].father=0;
	while(head<rear)
	{
		int i;
		for(i=0; i<4; i++)
		{
			que[rear]=que[head];
			int newx=que[head].n/3+dis[i][0];
			int newy=que[head].n%3+dis[i][1];
			if(newx<0||newy<0||newx>=3||newy>=3)
				continue;
			que[rear].n=newx*3+newy;
			int temp;
			temp=que[rear].pre[que[head].n];
			que[rear].pre[que[head].n]=que[rear].pre[que[rear].n];
			que[rear].pre[que[rear].n]=temp;
			que[rear].son=kangtuo(que[rear].pre);
			if(path[que[rear].son].father==-1)
			{
				path[que[rear].son].father=que[head].son;
				if(i==0)
					path[que[rear].son].way='u';
				if(i==1)
					path[que[rear].son].way='d';			
				if(i==2)
					path[que[rear].son].way='l';
				if(i==3)
					path[que[rear].son].way='r';
				rear++;				
			}
		}
		head++;
	}
}
void print(int n)
{
	if(n==0)
		return ;
	printf("%c", path[n].way);
	print(path[n].father);
}
int main()
{
	for(int i=0; i<370000; i++)
		path[i].father=-1;
	int a[10]={1,2,3,4,5,6,7,8,9};
	bfs(a);
	char prestr[30]={0};
	while(gets(prestr)!=NULL)
	{
		int str[10]={0};
		int j;
		for(int i=0,j=0; prestr[i]!='\0'; i++)
		{
			if(prestr[i]=='x')
				str[j++]=9;
			else if(prestr[i]==' ')
				continue;
			else
				str[j++]= prestr[i]-'0';
		}
		int ans=kangtuo(str);
		if(path[ans].father==-1)
			printf("unsolved");
		else
			print(ans);
		printf("\n");
	}
	return 0;
}