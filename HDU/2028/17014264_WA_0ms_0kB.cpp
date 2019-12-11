#include<stdio.h>
int main()
{
	int n,i,t,max,j,y=0;
	int a[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(t=a[0],i=0;i<n;i++)
			if(t<a[i])
				t=a[i];
		for(i=0,max=1;i<n;i++)
			max =max*a[i];
		for(i=1;t*i<=max;i++)
		{
			for(j=0,y=0;j<n;j++)
			   if((t*i)%a[j]==0)
                  y++;
			if(y==n)
			{
				max = t*i;
		    	break;
			}
		}
		printf("%d\n",max);
		
	}
	return 0;
}