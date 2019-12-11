#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int fib1[2][2]={0};
	int fib[2][2]={0};
	int ans[2][2]={0};
	int ans_[2][2]={0}; 
	while(scanf("%d",&n),n!=-1)
	{
		fib[0][0]=1,fib[0][1]=1,fib[1][0]=1,fib[1][1]=0;
		if(n>2)
		{
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				ans[i][j]=1;
		while(n)
		{
			if(n%2)
			{
				memset(ans_, 0, sizeof(ans_));
				int i,j,r,k;
				for(i=0; i<2; i++)
					for(r=0; r<2; r++)
						for(k=0; k<2; k++)
							ans_[i][r]+=(ans[i][k]*fib[k][r])%10000;
				for(i=0; i<2; i++)
					for(j=0; j<2; j++)
						ans[i][j]=ans_[i][j];
			}
			memset(ans_, 0, sizeof(ans_));
			for(int i=0; i<2; i++)
				for(int j=0; j<2; j++)
					fib1[i][j]=fib[i][j];		
			int i,j,r,k;
			for(i=0; i<2; i++)
				for(r=0; r<2; r++)
					for(k=0; k<2; k++)
						ans_[i][r]+=(fib[i][k]*fib1[k][r])%10000;
			for(i=0; i<2; i++)
				for(j=0; j<2; j++)
					fib[i][j]=ans_[i][j];
			n/=2;
		}
		printf("%d\n",ans[0][1]);
		}
		else
		{
			if(n==0)	printf("0\n");
			else 		printf("1\n");
		}
	}
	return 0;
}