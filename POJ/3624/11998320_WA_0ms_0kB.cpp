#include<stdio.h>
#include<string.h>
int num1[3000]={0};
int num2[3000]={0};
int vla[13000]={0};
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		int i,j;
		for(i=1; i<=N; i++)
		{
			scanf("%d%d",&num1[i],&num2[i]);
		}
		for(i=1; i<=N; i++)
		{
			for(j=M; j>=0; j--)
				if(j>=num1[i])
					vla[j]=max_(vla[j],vla[j-num1[i]]+num2[i]);
				else
					vla[j]=vla[j];
		}
		printf("%d\n",vla[M]);
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		memset(vla, 0, sizeof(vla));
	}
	return 0;
} 