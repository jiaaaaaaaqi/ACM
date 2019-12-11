#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=100005;
typedef long long ll;

int n,top;
struct Node
{
       ll x,y;
}p[MAX];
ll Cross(Node a,Node b,Node c)
{
       return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
  
ll dis(Node a,Node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
 bool cmp(Node a,Node b)
{  
   ll flag = Cross(p[1],a,b);
   if(flag != 0) return flag > 0;
   return dis(p[1],a) >= dis(p[1],b); 
}
  
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&p[i].x,&p[i].y);
        sort(p+2, p+1+n, cmp);
        p[n+1] = p[1];
        p[n+2] = p[2];
        bool flag = true;
        ll tmp = dis(p[1], p[2]);
        for (int i = 2; i <= n; i++) {
            if (tmp != dis(p[i], p[i+1])) {
                flag = false;
                break;
            }
        }

        ll tmp2 = dis(p[1],p[3]);
        for (int i = 2; i <= n; i++) {
            if (tmp2 != dis(p[i], p[i+2])) {
                flag = false;
                break;
            }
        }
        puts(flag?"YES":"NO");
    }
}