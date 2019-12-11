#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int flag=0;
		int i;
		int num;
		for(i=0; i<n; i++)
		{
			scanf("%d",&num);
			if(num==1)
				flag=1;
		}
		if(flag)
			printf("-1\n");
		else
			printf("1\n");
	}
	return 0;
}