#include<stdio.h>
#include<string.h>
struct node{
	int pre[10];
	int n;
};
struct Node{
	int cnt;
	char way;
};
int numx;
node que2[370000];
node que1[370000];
Node path[370000];
int vis1[370000];
int vis2[370000];
int fac[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int str[10]={0};

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
void bfs()
{
	memset(vis1, 0, sizeof(vis1));
	memset(vis2, 0, sizeof(vis2));
	memset(que1, 0, sizeof(que1));
	memset(que2, 0, sizeof(que2));
	memset(path, 0, sizeof(path));
	int a[10]={1,2,3,4,5,6,7,8,9};
	
	int head1=0;
	int rear1=1;
	int head2=0;
	int rear2=1;
	int count=2;
	
	for(int i=0; i<9; i++)
	{
		que1[0].pre[i]=str[i];
		que2[0].pre[i]=a[i];
	}
		
	que1[0].n=numx;
	que2[0].n=8;
	
	vis1[cantuo(str)]=1;
	vis2[cantuo(a)]=2;

	path[1].cnt=-1;
	path[2].cnt=-1;
		
	while(head1<rear1&&head2<rear2)
	{
		int i;
		int p=cantuo(que1[head1].pre);
		if(vis2[p])
		{
			print(vis2[p]);
			int k=vis2[p];
			while(path[k].cnt!=-1)
			{
				printf("%c", path[k].way);
				k=path[k].cnt;
			}
			return ;
		}
		
		for(i=0; i<4; i++)
		{
			for(int j=0; j<10; j++)
				que1[rear1].pre[j]=que1[head1].pre[j];
			int newx=que1[head1].n/3+dis[i][0];
			int newy=que1[head1].n%3+dis[i][1];
			if(newx<0||newy<0||newx>2||newy>2)
				continue;
			que1[rear1].n=3*newx+newy;
			que1[rear1].pre[que1[head1].n]=que1[rear1].pre[que1[rear1].n];
			que1[rear1].pre[que1[rear1].n]=9;
			int v=cantuo(que1[rear1].pre);
			if(vis1[v])
				continue;
			vis1[v]=++count;
			if(i==0)
				path[count].way='d';
			if(i==1)
				path[count].way='u';
			if(i==2)
				path[count].way='r';
			if(i==3)
				path[count].way='l';
			path[count].cnt=vis1[p];
			rear1++;
		}
		
		p=cantuo(que2[head2].pre);
		if(vis1[p])
		{
			print(vis1[p]);
			int k=vis2[p];
			while(path[k].cnt!=-1)
			{
				printf("%c", path[k].way);
				k=path[k].cnt;
			}
			printf("\n");
			return ;
		}
		for(i=0; i<4; i++)
		{
			int newx=que2[head2].n/3+dis[i][0];
			int newy=que2[head2].n%3+dis[i][1];
			if(newx<0||newy<0||newx>2||newy>2)
				continue;
			que2[rear2].n=newx*3+newy;
			que2[rear2].pre[que2[head2].n]=que2[rear2].pre[que2[rear2].n];
			que2[rear2].n=9;
			int v=cantuo(que2[rear2].pre);
			if(vis2[v])
				continue;
			vis2[v]=++count;
			if(i==0)
				path[count].way='u';
			if(i==1)
				path[count].way='d';
			if(i==2)
				path[count].way='l';
			if(i==3)
				path[count].way='r';
			path[count].cnt=vis2[p];
			rear2++;
		}
		head1++;
		head2++;
	}
	printf("unsolvable\n");
}

int main()
{
	char prestr[30]={0};
	while(gets(prestr)!=NULL)
	{
		int j;
		for(int i=0,j=0; prestr[i]!='\0'; i++)
		{
			if(prestr[i]=='x')
			{
				numx=j;
				str[j++]=9;
			}
			else if(prestr[i]==' ')
				continue;
			else
				str[j++]= prestr[i]-'0';
		}

		int num=0;
		for(int i=0; i<9; i++)
			for(int j=i+1; j<9; j++)
				if(str[j]<str[i])
					num++;

		if(!num&1)
			printf("unsolvable\n");
		else
			bfs();
		memset(prestr, 0, sizeof(prestr));
	}
	return 0;
} 