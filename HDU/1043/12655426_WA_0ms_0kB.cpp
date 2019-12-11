#include<stdio.h>
#include<string.h>
struct node{
	char way;
	int father;
	int pre[10];
	int son;
	int n;
};
node que[370000];
int fac[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int kangtuo(int a[])
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
void bfs(int a[])
{
	int head=0;
	int rear=1;
	for(int i=0; i<9; i++)
		que[0].pre[i]=a[i];
	que[0].n=8,que[0].son=0;
	que[0].father=0;
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
			int num=kangtuo(que[rear].pre);
			if(que[num].father==-1)
			{
				que[rear].n=newx*3+newy;
				int temp;
				temp=que[rear].pre[que[head].n];
				que[rear].pre[que[head].n]=que[rear].pre[que[rear].n];
				que[rear].pre[que[rear].n]=temp;
				que[rear].son=num;
				que[que[rear].son].father=que[head].son;
				if(i==0)
					que[que[rear].son].way='u';
				if(i==1)
					que[que[rear].son].way='d';			
				if(i==2)
					que[que[rear].son].way='l';
				if(i==3)
					que[que[rear].son].way='r';
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
	printf("%c", que[n].way);
	print(que[n].father);
}
int main()
{
	for(int i=0; i<370000; i++)
		que[i].father=-1;
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
		if(que[ans].father==-1)
			printf("unsolvable");
		else
			print(ans);
		printf("\n");
		memset(prestr, 0, sizeof(prestr));
	}
	return 0;
}