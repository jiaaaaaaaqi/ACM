#include<stdio.h>
int main()
{
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int ans;
		ans=2*n-1;
		printf("Case #%d: %d\n",cas++,ans);		
	} 
	return 0;
} 