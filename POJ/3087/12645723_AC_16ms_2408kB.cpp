#include<stdio.h>
#include<string.h>
int c,ans;
char s1[105]={0};
char s2[105]={0};
char  s[210]={0};
char vis[10000][210]={0};
void bfs()
{
	char  a[210]={0};
	char  b[210]={0};
	memset(vis, 0, sizeof(vis));
	int numvis=0;
	int cnt=1;
	int len=0;
	for(int i=0; i<c; i++)
	{
		a[len]=s2[i];
		len++;
		a[len]=s1[i];
		len++;
	}
	a[len]='\0';
	if(strcmp(a, s)==0)
	{
		ans=cnt;
		return ;
	}
	strcpy(vis[0], a);
	numvis++;
	while(1)
	{
		len=0;
		for(int i=0; i<c; i++)
		{
			b[len]=a[c+i];
			len++;
			b[len]=a[i];
			len++;
		}
		b[len]='\0';
		cnt++;
		if(strcmp(b, s)==0)
		{
			ans=cnt;
			return ;
		}
		int flag=0;
		for(int i=0; i<numvis; i++)
			if(strcmp(vis[i], b)==0)
			{
				flag=1;
				break;
			}
		if(flag)
			return ;
		strcpy(vis[numvis], b);
		numvis++;
		strcpy(a, b);
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
