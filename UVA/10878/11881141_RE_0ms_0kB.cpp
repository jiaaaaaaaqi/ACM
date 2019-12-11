#include<stdio.h>
int main()
{
	char str[500][20]={0};
	int num[11]={0,0,64,32,16,8,0,4,2,1,0};
	int i,j,time;
	int ans;
	time=0;
	for(i=0; ; i++)
	{
		gets(str[i]);
		if(str[i][0]=='_'&&i!=0)
		break;
		time++;
	}
	for(i=1; i<time; i++)
	{
		ans=0;
		for(j=0; j<11; j++)
		{
	        if(str[i][j]=='o')
	        ans+=num[j];
		}
		printf("%c",ans);
	}
	return 0;
}
