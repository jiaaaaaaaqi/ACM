#include<stdio.h>
long long int n,flag;
long long int ans;
void dfs(long long int x, int num)
{
	if(num>19||flag)
		return ;
	if(x%n==0)
	{
		ans=x;
		flag=1;
		return ;
	}
	dfs(x*10, num+1);
	dfs(x*10+1, num+1);
}
int main()
{
	while(scanf("%lld",&n), n)
	{
		flag=0;
		dfs(1,1);
		printf("%lld\n", ans);
	}
	return 0;
}