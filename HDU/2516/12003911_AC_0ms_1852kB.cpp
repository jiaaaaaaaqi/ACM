#include<stdio.h>
int main()
{
	int f[1000]={0};
	f[0]=1; f[1]=2;
	for(int i=2; i<1000; i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	int n;
	while(scanf("%d",&n),n)
	{
		int flag=0;
		for(int i=1; i<1000; i++)
			if(f[i]==n)
			{
				flag=1;
				break;
			}
		if(flag)
			printf("Second win");
		else
			printf("First win");
		printf("\n");
	}
	return 0;
}