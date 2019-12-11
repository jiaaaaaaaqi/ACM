#include <stdio.h>
#include <string.h>

long long num[1000005];
int main()
{
	int T;
	scanf("%d",&T);
	
	while (T--)
	{
		memset(num,0,sizeof(num));
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		num[1] = a;
		num[2] = b;
		int flag = 0;
		for (int i = 3; i < 1000000; i++)
		{
			num[i] = num[i-1] + num[i-2];
			if (num[i] > 1000000000) break;
			if (num[i] == c)
			{
				flag  = 1;
				break;
			}
			if (num[i] > c)
			{
				flag = 0;
				break;
			}
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	
	return 0;
 } 