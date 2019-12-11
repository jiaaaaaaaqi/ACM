#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		if(n==1)
			printf("Kiki\n");
		else
		{
			while(n)
			{
				if(n%2)
					ans++;
				n/=2;
			}
			if(ans%2)
				printf("Kiki\n");
			else
				printf("Cici\n");
		}
	}
	return 0;
}