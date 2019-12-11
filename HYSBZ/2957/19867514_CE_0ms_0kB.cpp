#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
ll h[maxn];
int block, n, m, num, belong[maxn];
double k[maxn];

void build(){
    block = sqrt(n);
    memset(h, 0, sizeof(h));
    memset(k, 0, sizeof(k));
    for(int i = 1; i <= n; i++){
        belong[i] = (i-1)/block+1;
    }
    num = (n-1)/block+1;
}
int L(int x){
    return (x-1)*block+1;
}
int R(int x){
    return min(n, x*block);
}
void update(int pos, ll c){
    int b = belong[pos];
    if(c*1.0/pos < k[b] && h[pos]*1.0/pos < k[b]){
        h[pos] = c;
    }
    else if(c*1.0/pos >= k[b]){
        h[pos] = c;
        k[b] = c*1.0/pos;
    }
    else{
        h[pos] = c;
        k[b] = 0.0;
        for(int i = L(b); i <= R(b); i++){
            k[b] = max(k[b], h[i]*1.0/i);
        }
    }
}

int query(){
    int ans = 0;
    double now = 0;
    for(int i = 1; i <= num; i++){
        if(k[i] > now){
            for(int j = L(i); j <= R(i); j++){
             //   printf("j = %d, k = %f, now = %f\n", j, h[j]*1.0/j, now);
                if(h[j]*1.0/j > now){
                    ans++;
                    now = h[j]*1.0/j;
                }
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d%d", &n, &m);
    build();
    int x;
    ll y;
    for(int i = 1; i <= m; i++){
        scanf("%d%lld", &x, &y);
        update(x,y);
        printf("%d\n", query());
    }
    return 0;
}



