#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int maxn=522;
ll a,b,c,d;
ll mod=998244353;

long long pow_mod(long long a,long long b){     
	long long ans=1;
	while(b!=0){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		//2^(a+b)+(b+d+1)*2^(a+c)-(1+b)*2^a
		ll ans = 0;
		ans = pow_mod(2,a+b)+(b+d+1)*pow_mod(2,a+c)%mod-(1+b)*pow_mod(2,a);
		ans = ans%mod;
		ans = ans+mod;
		ans  %= mod;
		printf("%lld\n",ans);
	}
	return 0;
}