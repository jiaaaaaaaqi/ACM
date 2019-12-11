#include<stdio.h>
#include<string.h>
int main()
{
	char cha[26]={0};
	char a[100][100]={0};
	int i=0,j=0;
	int x_move[3]={1,-1,1};
	int y_move[3]={0,1,0};
	for(i=0; i<26; i++)
		cha[i]=i+'a';
	memset(a, 1, sizeof(a));
	int size=3;
	int time=0;
	int v=0;
	int tern;
	int z;
	int x=3;
	for(size=3; size<=10; size++)
	{
		i=0;
		j=0;
		tern=size-1;
		while(x--)
		{
			for(z=0; z<=tern; z++)
			{
				a[i][j]=cha[time];
                if(z!=tern)
				{
                	i+=x_move[v];
					j+=y_move[v];
					time++;
					if(time==26)
						time=0;
				}
			}
			v++; 		
		}
		time++;
		if(time==26)
			time=0;
		x=3;
		v=0;
		int i_,j_;
		for(i_=0; i_<size; i_++)
		{
			for(j_=0; j_<size; j_++)
				if(a[i_][j_]!=1)
					printf("%c",a[i_][j_]);
			else
				printf(" ");
			printf("\n");
		}
		memset(a, 0, sizeof(a));
	}
	return 0;
}
