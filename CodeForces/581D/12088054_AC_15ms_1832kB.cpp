#include<stdio.h>
#include<string.h>
struct bill{
    int l;
    int w;
    char c;
};
int main()
{
    struct bill n[3]={0};
    int i,j,z;
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int time=3;     
        int flag=0;
        int max,mid,min;
        int max_l,mid_l,min_l; 
        i=0;
        while(time--)           
        {
            n[i].c=i+'A';
            n[i].l= a> b ? a:b;
            n[i].w= a<=b ? a:b;
            i++;
            if(time)
            {
                scanf("%d%d",&a,&b);
            }
        }
         
        if(n[0].l==n[1].l && n[1].l==n[2].l )        
        {                                               
            max_l=n[0].l;
            if(n[0].w + n[1].w + n[2].w == n[0].l)          
            {                                           
                printf("%d\n",max_l);
                flag=1;
                for(z=0; z<3; z++)
                {
                    for(i=0; i<n[z].w; i++)
                    {
                        for(j=0; j<n[z].l; j++)
                            printf("%c",n[z].c);
                    printf("\n");
                    }
                }
            }
        }
         
        else                                               
        {
            max=0,min=0;
            for(i=1; i<3; i++)
            {
                max=n[i].l>n[max].l ? i:max;
                min=n[i].l<n[min].l ? i:min;
            }
            mid=3-max-min;
            max_l=n[max].l;
            if((n[min].w+n[mid].w==n[max].l)&&(n[min].l==n[mid].l)&&(n[min].l+n[max].w==n[max].l))
            {
                flag=1;
                printf("%d\n",n[max].l);
                for(i=0; i<n[max].w; i++)
                {
                    for(j=0; j<n[max].l; j++)
                        printf("%c",n[max].c);
                    printf("\n");
                }
                for(i=0; i<n[min].l; i++)
                {
                    for(j=0; j<n[min].w; j++)
                        printf("%c",n[min].c);
                    for(j=0; j<n[mid].w; j++)
                        printf("%c",n[mid].c);
                    printf("\n");
                }
            }   
 
            else if((n[max].l==n[min].w+n[mid].l)&&(n[max].w+n[min].l==n[max].l)&&(n[min].l==n[mid].w))
            {
                flag=1;
                printf("%d\n",n[max].l);
                for(i=0; i<n[max].w; i++)
                {
                    for(j=0; j<n[max].l; j++)
                        printf("%c",n[max].c);
                    printf("\n");
                }
                for(i=0; i<n[min].l; i++)
                {
                    for(j=0; j<n[min].w; j++)
                        printf("%c",n[min].c);
                    for(j=0; j<n[mid].l; j++)
                        printf("%c",n[mid].c);
                    printf("\n");
                }               
            }
 
            else if((n[max].l==n[mid].w+n[min].l)&&(n[max].w+n[mid].l==n[max].l)&&(n[mid].l==n[min].w))
            {
                flag=1;
                printf("%d\n",n[max].l);
                for(i=0; i<n[max].w; i++)
                {
                    for(j=0; j<n[max].l; j++)
                        printf("%c",n[max].c);
                    printf("\n");
                }
                for(i=0; i<n[mid].l; i++)
                {
                    for(j=0; j<n[min].l; j++)
                        printf("%c",n[min].c);
                    for(j=0; j<n[mid].w; j++)
                        printf("%c",n[mid].c);
                    printf("\n");
                }               
            }
 
            else if((n[min].l+n[mid].l==n[max].l)&&(n[min].w==n[mid].w)&&(n[min].w+n[max].w==n[max].l))
            {
                flag=1;
                printf("%d\n",n[max].l);
                for(i=0; i<n[max].w; i++)
                {
                    for(j=0; j<n[max].l; j++)
                        printf("%c",n[max].c);
                    printf("\n");
                }
                for(i=0; i<n[mid].w; i++)
                {
                    for(j=0; j<n[min].l; j++)
                        printf("%c",n[min].c);
                    for(j=0; j<n[mid].l; j++)
                        printf("%c",n[mid].c);
                    printf("\n");
                }
            }   
             
        }
         
        if(!flag)
            printf("-1\n");
        memset(n, 0, sizeof(n)); 
    }
    return 0;
}