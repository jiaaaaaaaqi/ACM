#include<stdio.h>
#include<string.h>
#include<ctype.h> 
int main()
{
	int r,c,i1,i2,j;
	char str[100][100];
	r=0;
	int num=1;
	while(scanf("%s",str[r])!=EOF)
	{
		if(str[r][0]=='9')
		{
			int flag=0;
			for(i1=0; i1<r; i1++)
			{
				for(i2=0; i2<r; i2++)
				{
					if(i1!=i2)
					{
					int num2=0;
					int len1=strlen(str[i1]);
					int len2=strlen(str[i2]);
					if(len1<=len2)
					{
						for(j=0; j<len1; j++)
							if(str[i1][j]==str[i2][j])
								num2++;
						if(num2==len1)
						{
						flag=1;
						break;
						}
					}
					}
					else 
						continue;
				} 
				if(flag==1)
				break;
			}
			if(flag!=1)
			printf("Set %d is immediately decodable",num);
			else
			printf("Set %d is not immediately decodable",num);
			num++;
			printf("\n");
		}
		else 
		r++;
	}
	return 0;
}