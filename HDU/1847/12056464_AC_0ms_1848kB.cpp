#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n%3)
			printf("Kiki\n");
		else
			printf("Cici\n");
	}
	return 0;
}