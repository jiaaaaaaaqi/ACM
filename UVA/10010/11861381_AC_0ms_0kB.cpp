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
		char str2[100][100];
		int x_move[8]={-1,-1,-1,0,0,1,1,1};
		int y_move[8]={-1,0,1,-1,1,-1,0,1};
		
		scanf("%d%d",&R1,&C1);
		getchar();
		for(i=0; i<R1; i++)
			scanf("%s",str1[i]);
		for(i=0; i<R1; i++)
			for(j=0; j<C1; j++)
				str1[i][j]=toupper(str1[i][j]); 
				
		scanf("%d",&R2);
		getchar();
		for(i=0; i<R2; i++)
			scanf("%s",str2[i]);
		for(i=0; i<R2; i++)
			for(j=0; str2[i][j]!='\0'; j++)
				str2[i][j]=toupper(str2[i][j]);
	
		for(int z=0; z<R2; z++)	
		{
			int len=strlen(str2[z]);
			int flag=0;
			int c;
			int m;
			for(i=0; i<R1; i++)
			{
				for(j=0; j<C1; j++)
				{
				if(str1[i][j]==str2[z][0])
				{
					int x=i;
					int y=j;
					int fx,fy;
					for(m=0; m<8; m++)
					{
						fx=x+x_move[m];
						fy=y+y_move[m];
						c=1;
						if(!(fx<0||fy<0||fx>=R1||fy>=C1))
						{
						while(str1[fx][fy]==str2[z][c])
						{
							fx=fx+x_move[m];
							fy=fy+y_move[m];
							c++;
							if(fx<0||fy<0||fx>=R1||fy>=C1)
							break;						
						}
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
			printf("\n");	
		}
	if(N!=0)
	printf("\n");
	}
	return 0;
}