#include<stdio.h>
int main()
{
	int i, n, t;
	char str[50];
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		gets(str);
		if ((str[0] == '_') || (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
		{
			for (i = 0, t = 1; str[i] != '\0'; i++)
			{
				if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '_') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
				{
					t = 0;
					break;
				}

			}
			if (t == 0)
				printf("no\n");
			else
				printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}