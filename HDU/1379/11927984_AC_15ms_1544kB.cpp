#include<stdio.h>
#include<string.h>
int num[2000]={0};
char str[2000][2000];
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		int r,c;
		int i,j,j2;
		scanf("%d%d",&c,&r);
		getchar();
		for(i=0; i<r; i++)
		{
			gets(str[i]);
		}
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				for(j2=j+1; j2<c; j2++)
				{
					if(str[i][j2]<str[i][j])
						num[i]++;
				}
			}
		}
		int max;
		int num2;
		int n=0;
		
		while(n<r)
		{
			max=num[0];
			num2=0;
			for(i=0; i<r; i++)
			{
				if(num[i]<max)
				{
					max=num[i];
					num2=i;
				}
			}
			num[num2]=9999;
			printf("%s\n",str[num2]);
			n++;
		}
	}
	return 0;
}
