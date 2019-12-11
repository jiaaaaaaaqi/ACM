#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int M,N;
	int z=1;
	while(scanf("%d%d",&M,&N)!=EOF)
	{
		int fx,fy;
		int i,j,m,n,time;
		int num[30]={0};
		char key[30][200];
		char str[30][200];
		for(i=0; i<M; i++)
			scanf("%s",key[i]);
		getchar();
		for(i=0; i<N; i++)
			gets(str[i]);
		for(i=0; i<N; i++)
		{
		int len1=strlen(str[i]);
			for(j=0; j<len1; j++)
			{	

				if(j==0)	
				{
					for(m=0; m<M; m++)
					{
						int len2=strlen(key[m]);
						if(key[m][0]==(tolower(str[i][0])))
						{
						fx=1,fy=1,time=1;
						if(fx<len2&&fy<len1)
						{
						while(key[m][fx]==str[i][fy]||key[m][fx]==str[i][fy]+32)
						{
							fx++,fy++;
							time++;
							if(fx==len2||fy==len1)
							break;
						}
						}
						if(time==len2)//1
							if(str[i][time]==' '||str[i][time]==','||str[i][time]=='.'||
								str[i][time]=='?'||str[i][time]=='!'||str[i][time]=='\0'||
								 (str[i][time]>='0'&&str[i][time]<='9')||str[i][time]=='"')
							num[i]++;
						}
					}
				}

				else
				{				//2
					if(str[i][j-1]==' '||str[i][j-1]=='.'||str[i][j-1]==','||str[i][j-1]=='"'||
					   str[i][j-1]=='?'||str[i][j-1]=='!'||(str[i][j-1]>='0'&&str[i][j-1]<='9'))
					{
						for(m=0; m<M; m++)
						{
						int len2=strlen(key[m]);
						fx=0,fy=j,time=0;
						if(fx<len2&&fy<len1)
						{
						while(key[m][fx]==str[i][fy]||key[m][fx]==str[i][fy]+32)
						{
							fx++,fy++;
							time++;
							if(fx==len2||fy==len1)
							break;
						}
						}
						if(time==len2)//3
							if(str[i][j+time]==' '||str[i][j+time]==','||str[i][j+time]=='.'||
								str[i][j+time]=='?'||str[i][j+time]=='!'||str[i][j+time]=='\0'||
								(str[i][j+time]>='0'&&str[i][j+time]<='9')||str[i][j+time]=='"')
							num[i]++;	
						}	
					}
				}
			}
		}
		int max=num[0];
		for(i=1; i<N; i++)
			max=max>num[i] ? max:num[i];
		printf("Excuse Set #%d\n",z);
		for(i=0; i<N; i++)
		{
			if(num[i]==max)
				printf("%s\n",str[i]);
		}
		printf("\n");
		z++;
	}
	return 0;
}