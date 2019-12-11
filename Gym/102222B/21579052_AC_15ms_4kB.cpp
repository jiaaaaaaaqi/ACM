#include<bits/stdc++.h>
using namespace std;
const int pi = acos(-1.0);
struct point{
    double x,y;
}p[105];
double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double ang(point a,point b,point c){
	point q,p;
	p.x = b.x-a.x; 
	p.y = b.y-a.y;
	q.x = c.x-b.x;
	q.y = c.y-b.y;
    return acos((p.x*q.x+q.y*p.y)/sqrt(p.x*p.x+p.y*p.y)/sqrt(q.x*q.x+q.y*q.y));
}
int main(){
	int t,n;
    scanf("%d",&t);
    int ca = 1;
    while(t--){
    	point q;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        scanf("%lf%lf",&q.x,&q.y);
        double ans=0;
        for(int i = 0; i < n; i++)   ans+=dis(q,p[(i+1)%n])*ang(p[i],p[(i+1)%n],p[(i+2)%n]);
        printf("Case #%d: %.3f\n",ca++,ans);
    }
    return 0;
}