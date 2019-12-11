#include<stdio.h>
int a[1000000]={0};
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	int num;
	char c;
	int sum=0,wei=0;
	while(N--)
	{
		scanf("%c %d",&c,&num);
		getchar();
		if(c=='+')
		{
			if(!wei)
				sum++;
			else
				wei--;
			a[num]=1;
		}
		if(c=='-')
		{
			if(a[num])
			{
				wei++;
			}
			else
			{
				sum++;
				wei++;
			}
			a[num]=0;
		}
	}
	printf("%d\n",sum);
	return 0;
}