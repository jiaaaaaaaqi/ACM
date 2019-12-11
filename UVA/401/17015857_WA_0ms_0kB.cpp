#include<stdio.h>
#include<string.h>
int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	char str[10005];
	char sample[36]={'A','\0','\0','\0','3','\0',
	'\0','H','I','L','\0','J','M','\0','O','\0','\0',
	'\0','2','T','U','V','W','X','Y','5','1','S','E',
	'\0','Z','\0','\0','8','\0'};
	while(gets(str)!=NULL)
	{
		int len = strlen(str);
		int flag[2]={1,1};
		for(int i=0;i<len/2;i++)
		{
			if(str[i]!=str[len-1-i])
				flag[0] = 0;
			if(str[i]!=sample[str[len-1-i]-'A']&&str[i]!=sample[str[len-1-i]-'1'+26])
			{
				flag[1] = 0;
			}
		}
		if(len%2 == 1&&str[len/2]!=sample[str[len/2]-'A']&&str[len/2]!=sample[str[len/2]-'1'+26])
		{
			flag[1] = 0; 
		}
		if(flag[0] == 1&&flag[1] == 1)
			printf("%s -- is a mirrored palindrome.\n\n",str);
		else if(flag[1] == 1&&flag[0] == 0)
			printf("%s -- is a mirrored string.\n\n",str);
		else if(flag[1] == 0&&flag[0] == 1)
			printf("%s -- is a regular palindrome.\n\n",str);
		else if(flag[1] == 0&&flag[0] == 0)
			printf("%s -- is not a palindrome.\n\n",str);
		memset(str, 0, sizeof str);
	}
	return 0;
}