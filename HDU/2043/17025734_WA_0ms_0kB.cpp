#include<stdio.h>
int main()
{
    char str[50];
	int n,i,j;
	int a[4];
	scanf("%d",&n);
	while(n--)
	{
		getchar();
		gets(str);
        for(i=0;str[i]!='\0';i++);
        if(i<8||i>16)
		{
			printf("NO\n");
			continue;
		}
		else
		{
           for(i=0,a[0]=a[1]=a[2]=a[3]=0;str[i]!='\0';i++)
		   {
			   if(str[i]>='A'&&str[i]<='Z'){
				   a[0]++;continue;}
               if(str[i]>='a'&&str[i]<='z'){
				   a[1]++;continue;}
			   if(str[i]>='0'&&str[i]<='9'){
				   a[2]++;continue;}
			   if(str[i]=='~'||str[i]=='!'||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='%'||str[i]=='^'){
				   a[3]++;continue;}
			   else
				   break;
		   }
		}
		  for(i=0,j=0;i<4;i++)
			   if(a[i]==0)
				   j++;
		   if(j<=1)
			   printf("YES\n");
		   else
			   printf("NO\n");
		}
	return 0;
}