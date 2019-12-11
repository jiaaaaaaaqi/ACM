#include<stdio.h>
int main()
{	
	int a,b,c,d;
	while(scanf("%d.%d.%d.%d",&a,&b,&c,&d)!=EOF)
	{
		int flag=0;
		if(a>255)	flag=1;
		if(b>255)	flag=1;
		if(c>255)	flag=1;
		if(d>255)	flag=1;
		if(flag==0)
		printf("YES\n");
		else 
		printf("NO\n");
	}
	return 0;
} 