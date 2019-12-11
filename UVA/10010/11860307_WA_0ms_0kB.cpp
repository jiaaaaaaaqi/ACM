#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		int R1,C1,R2,C2,i,j;
		char str1[100][100];
		char str2[100];
		int x_move[8]={-1,-1,-1,0,0,1,1,1};
		int y_move[8]={-1,0,1,-1,1,-1,0,1};
		scanf("%d%d",&R1,&C1);
		getchar();
		for(i=0; i<R1; i++)
		{
				scanf("%s",&str1[i]);
			getchar();
		}
		for(i=0; i<R1; i++)
			for(j=0; j<C1; j++)
				str1[i][j]=toupper(str1[i][j]);
		scanf("%d",&R2);
		getchar();
		while(R2--)
		{
			scanf("%s",str2);
			int len=strlen(str2);
			for(i=0; i<len; i++)
					str2[i]=toupper(str2[i]);
			int flag=0;
			int c;
			int m;
			for(i=0; i<R1; i++)
			{
				for(j=0; j<C1; j++)
				{
				if(str1[i][j]==str2[0])
				{
					int x=i;
					int y=j;
					int fx,fy;
					for(m=0; m<8; m++)
					{
						fx=x+x_move[m];
						fy=y+y_move[m];
						c=1;
						while(str1[fx][fy]==str2[c])
						{
							fx=fx+x_move[m];
							fy=fy+y_move[m];
							c++;
						}
						if(c==len)
						{
							flag=1;
							printf("%d %d",x+1,y+1);
							break;
						}
					}
					if(flag==1)
					break;
				}
				}
			if(flag==1)
			break;	
			}
		if(R2)
			printf("\n\n");
		}
	}
	return 0;
}