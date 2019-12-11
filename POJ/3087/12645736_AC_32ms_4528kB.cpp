#include<stdio.h>
#include<string.h>
struct node{
	char a[210];
	int cnt;
};
int c,ans;
node que[10000];
char s1[105]={0};
char s2[105]={0};
char  s[210]={0};
char vis[10000][210]={0};
void bfs()
{
	memset(vis, 0, sizeof(vis));
	memset(que, 0, sizeof(que));
	int head=0;
	int rear=1;
	int numvis=0;
	que[0].cnt=1;
	int len=0;
	for(int i=0; i<c; i++)
	{
		que[0].a[len]=s2[i];
		len++;
		que[0].a[len]=s1[i];
		len++;
	}
	que[0].a[len]='\0';
//	printf("%d  %s\n",strlen(que[0].a), que[0].a);
	if(strcmp(que[0].a, s)==0)
	{
		ans=1;
		return ;
	}
	strcpy(vis[0], que[0].a);
	numvis++;
	while(1)
	{
		len=0;
		for(int i=0; i<c; i++)
		{
			que[rear].a[len]=que[head].a[c+i];
			len++;
			que[rear].a[len]=que[head].a[i];
			len++;
		}
		que[rear].a[len]='\0';
		que[rear].cnt=que[head].cnt+1;
		int flag=0;
		for(int i=0; i<numvis; i++)
			if(strcmp(vis[i], que[rear].a)==0)
			{
				flag=1;
				break;
			}
		if(flag)
			return ;
		strcpy(vis[numvis], que[rear].a);
		numvis++;
		if(strcmp(que[rear].a, s)==0)
		{
			ans=que[rear].cnt;
			return ;
		}
		head++;
		rear++;
	}
}
int main()
{
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--)
	{
		ans=-1;
		scanf("%d",&c);
		scanf("%s%s%s",s1,s2,s);
		bfs();
		printf("%d %d\n",cas++,ans);
	}
	return 0;
}
