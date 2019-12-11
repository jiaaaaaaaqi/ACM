#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        char str[200] = {0};
        double quality = 0;
        gets(str);
        int len = strlen(str);
        for(int i=0;i<len;i++)
        {
            if((str[i+1]>'9'||str[i+1]<'0')||i+1 == len)
            {
                if(str[i] == 'C')
                    quality += 12.01;
                else if(str[i] == 'H')
                    quality += 1.008;
                else if(str[i] == 'O')
                    quality += 16.00;
                else if(str[i] == 'N')
                    quality += 14.01;
            }
            else
            {
                int multiple;
                if(str[i+2] <= '9'&&str[i+2] >='0'&&i+2!=len)
                    multiple = (str[i+1]-'0')*10 + (str[i+2]-'0');
                else
                    multiple = str[i+1]-'0';
                if(str[i] == 'C')
                    quality += 12.01*multiple;
                else if(str[i] == 'H')
                    quality += 1.008*multiple;
                else if(str[i] == 'O')
                    quality += 16.00*multiple;
                else if(str[i] == 'N')
                    quality += 14.01*multiple;
                if(multiple>9)
                    i+=2;
                else
                    i++;
            }
        }
        printf("%.3f\n",quality);
    }
    return 0;
 } 
