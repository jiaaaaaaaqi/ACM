#include <iostream>  
#include<stdio.h>  
long long int  fast_mul(long long int a,long long int b,long long int c)  
{  
    a=a%c;  
    b=b%c;  
    long long int ans=0;  
    while(b) 
    {  
	    if(b&1)  
	    {  
	        ans=ans+a;  
	    	if(ans>c)
				ans-=c;  
 	 	}  
	    a=a<<1; 
	    if(a>=c)
			a-=c;  
	    b>>=1;  
    }  
    return ans;  
}  
int main()  
{  
    long long int a,b,c,ans;  
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)  
    {  
        ans=1;  
        a=a%c;  
        while(b)  
        {  
            if(b&1)  
	            ans=fast_mul(ans,a,c);  
            a=fast_mul(a,a,c);  
            b>>=1;  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
}  
