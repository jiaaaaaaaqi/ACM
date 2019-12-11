#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000;
const double eps = 1e-6;
const int maxn = 10000+5;
double l,w;
int n;
struct node{
    double v,rr,l,r;
    bool operator < (const node& rhs) const {
        return l < rhs.l;
    }
}a[maxn],b;
int main() {
    while(~scanf("%d%lf%lf",&n,&l,&w)) {
        int cnt = 0;
        for(int i=0;i<n;i++) {
            scanf("%lf%lf",&b.v,&b.rr);
            if(b.rr < w/2 || fabs(b.rr-w/2) < eps) continue; 
            double u = sqrt(b.rr*b.rr - w/2.0*w/2.0);
            a[cnt].rr = b.rr; a[cnt].v = b.v;
            a[cnt].l = b.v - u; a[cnt++].r = b.v + u;
        }
        sort(a,a+cnt);
        int ans = 0;
        double cur_l = 0, cur_r = 0;
        for(int i=0;i<cnt;i++) {
            if(cur_l > a[i].l || fabs(cur_l-a[i].l) < eps) 
                cur_r = max(cur_r,a[i].r);
            else {
                if(fabs(cur_l - cur_r)>eps) {
                    cur_l = cur_r;
                    ans++; i--;
                }
            }
            if(i == cnt-1 && (cur_l > a[i].l || fabs(cur_l-a[i].l) < eps)) {
                cur_l = cur_r ; ans++;
            }
        }
        if(cur_l > l || fabs(cur_l - l) < eps) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
