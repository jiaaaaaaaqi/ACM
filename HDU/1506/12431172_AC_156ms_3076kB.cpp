#include<stdio.h>
#include<string.h>
long long int h[100005]={0};
int l[100005]={0};
int r[100005]={0}; 
int main()
{
	int n;
	while(scanf("%d",&n), n)
	{
		int i;
		for(i=1; i<=n; i++)
		{
			scanf("%d",&h[i]);
			l[i]=r[i]=i;
		}
		h[0]=h[n+1]=-1;
		for(i=1; i<=n; i++)
			while(h[l[i]-1]>=h[i])
				l[i]=l[l[i]-1];
		for(i=n; i>=1; i--)
			while(h[r[i]+1]>=h[i])
				r[i]=r[r[i]+1];
		long long int ans=0;
		for(i=1; i<=n; i++)
			ans = ans > (h[i]*(r[i]-l[i]+1)) ? ans:(h[i]*(r[i]-l[i]+1));
		printf("%lld\n",ans);
		memset(h, 0, sizeof(h));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
	}
	return 0;
}
 