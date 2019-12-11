#include<stdio.h>
#include<string.h>
int vis[10000]={0};
char str[10000][2]={0};
int flag,l;
void dfs(int num)
{
	if(str[num][1]=='m')
		flag=1;
	if(flag)
		return ;
	for(int i=0; i<l; i++)
	{
		if(str[i][0]==str[num][1]&&vis[i]==0)
		{
			vis[i]=1;
			dfs(i);
		}
	}
}
int main()
{
	char prestr[1000];
	while(scanf("%s",prestr)!=EOF)
	{
		if(!strcmp(prestr, "0"))
		{
			printf("No.\n");
			continue;
		}
		l=0;
		str[l][0]=prestr[0];
		str[l][1]=prestr[strlen(prestr)-1];
		while(scanf("%s",prestr), strcmp(prestr, "0"))
		{
			l++;
			str[l][0]=prestr[0];
			str[l][1]=prestr[strlen(prestr)-1];
		}
		l++;
/*		for(int i=0; i<l; i++)
			printf("%c %c\n",str[i][0], str[i][1]);*/
		flag=0;
		for(int i=0; i<l; i++)
		{
			if(str[i][0]=='b')
			{
				memset(vis, 0, sizeof(vis));
				vis[i]=1;
				dfs(i);
			}
			if(flag)
				break;
		}
		if(flag)
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}