/*
		  .
		 ';;;;;.
		'!;;;;;;!;`
	   '!;|&#@|;;;;!:
	  `;;!&####@|;;;;!:
	 .;;;!&@$$%|!;;;;;;!'.`:::::'.
	 '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
	 :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`	'!%&#########@$!:.
	 ;!;;!!;;;;;|$$&@##$;;;::'''''::;;;;|&|%@$|;;;;;;;;;;;;;;;;!$;
	 ;|;;;;;;;;;;;;;;;;;;!%@#####&!:::;!;;;;;;;;;;!&####@%!;;;;$%`
	`!!;;;;;;;;;;!|%%|!!;::;;|@##%|$|;;;;;;;;;;;;!|%$#####%;;;%&;
	:@###&!:;;!!||%%%%%|!;;;;;||;;;;||!$&&@@%;;;;;;;|$$##$;;;%@|
	;|::;;;;;;;;;;;;|&&$|;;!$@&$!;;;;!;;;;;;;;;;;;;;;;!%|;;;%@%.
   `!!;;;;;;;!!!!;;;;;$@@@&&&&&@$!;!%|;;;;!||!;;;;;!|%%%!;;%@|.
%&&$!;;;;;!;;;;;;;;;;;|$&&&&&&&&&@@%!%%;!||!;;;;;;;;;;;;;$##!
!%;;;;;;!%!:;;;;;;;;;;!$&&&&&&&&&&@##&%|||;;;!!||!;;;;;;;$&:
':|@###%;:;;;;;;;;;;;;!%$&&&&&&@@$!;;;;;;;!!!;;;;;%&!;;|&%.
 !@|;;;;;;;;;;;;;;;;;;|%|$&&$%&&|;;;;;;;;;;;;!;;;;;!&@@&'
  .:%#&!;;;;;;;;;;;;;;!%|$$%%&@%;;;;;;;;;;;;;;;;;;;!&@:
  .%$;;;;;;;;;;;;;;;;;;|$$$$@&|;;;;;;;;;;;;;;;;;;;;%@%.
	!&!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|@#;
	 `%$!;;;;;;;;;;;$@|;;;;;;;;;;;;;;;;;;;;;;;;!%$@#@|.
	   .|@%!;;;;;;;;;!$&%||;;;;;;;;;;;;;;;;;!%$$$$$@#|.
		   ;&$!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;%#####|.
		   |##$|!;;;;;;::'':;;;;;;;;;;;;;!%$$$@#@;
		  ;@&|;;;;;;;::'''''':;;;;;;;|$&@###@|`
		.%##@|;;;;:::''''''''''::;!%&##$'
	  `$##@$$@@&|!!;;;:'''''::::;;;;;|&#%.
	;&@##&$%!;;;;;;::''''''''::;!|%$@#@&@@:
	 .%@&$$|;;;;;;;;;;:'''':''''::;;;%@#@@#%.
	:@##@###@$$$$$|;;:'''':;;!!;;;;;;!$#@@#$;`
	 `%@$$|;;;;;;;;:'''''''::;;;;|%$$|!!&###&'
	 |##&%!;;;;;::''''''''''''::;;;;;;;!$@&:`!'
	:;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:				 !@#$'
	  |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:			  '%%!%&;
	  |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`			'%$|!%&;
	  |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:		   .|%;:!&%`
	  !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;		  `%&%!!$&:
	  '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;		 !$!;:!$&:
	   |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'	  `%$|%%;|&$'
		|&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
		`%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
		!&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
	   '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
	   .!%%&%'`|$;	   :|$#%|@#&;%#%.
*/
#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int sgn(double x) {
    if(fabs(x) < eps)	return 0;
    return x > 0 ? 1 : -1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b) {
        x = a, y = b;
    }
    bool operator == (Point a) {
        return sgn(x-a.x) == 0 && sgn(y-a.y) == 0;
    }
    bool operator < (Point a) {     //最左下角
        return sgn(y-a.y) == 0 ? sgn(x-a.x)<0 : y<a.y;
    }
    Point operator - (Point a) {
        return Point(x-a.x, y-a.y);		//向量减
    }
    Point operator + (Point a) {
        return Point(x+a.x, y+a.y);		//向量加
    }
    double operator * (Point a) {	//点乘(内积)
        return x*a.x + y*a.y;
    }
    double operator ^ (Point a) {	//叉乘(外积)
        return x*a.y - y*a.x;
    }
    Point operator * (double k) {
        return Point(x*k, y*k);
    }
    Point operator / (double k) {
        return Point(x/k, y/k);
    }
    Point trunc(double r) {
        //化为长度为 r 的向量
        double l = len();
        if(!sgn(l))	return *this;
        r /= l;
        return Point(x*r, y*r);
    }
    Point rotleft() {
        //原向量逆时针旋转90度
        return Point(-y, x);
    }
    Point rotright() {
        //原向量顺时针旋转90度
        return Point(y, -x);
    }
    Point rotate(Point p, double rad) {
        //原向量绕着 p 点逆时针旋转 rad 度
        Point v = (*this) - p;
        double c = cos(rad), s = sin(rad);
        return Point(p.x + v.x*c - v.y*s, p.y + v.x*s + v.y*c);
    }
    double len() {			//向量长度
        return hypot(x, y);
    }
    double len2() {			//向量长度平方
        return x*x + y*y;
    }
    double distance(Point p) {	//两点之间距离
        return hypot(x-p.x, y-p.y);
    }
    double rad(Point a, Point b) {
        //三个点:p, a, b
        //计算 pa 与 pb 所成的夹角
        Point p = *this;
        return fabs(atan2(fabs((a-p) ^ (b-p)), (a-p) * (b-p)));
    }
};

struct Line {
    Point s, e;
    Line() {};
    Line(Point _s, Point _e) {
        // 两点确定直线
        s = _s, e = _e;
    }
    Line(Point p, double angle) {
        //根据点 p 和倾斜角 angle 确定直线, 0 <= angle <= pi
        s = p;
        if(sgn(angle - pi/2) == 0) {
            e = (s + Point(0, 1));
        } else {
            e = (s + Point(1, tan(angle)));
        }
    }
    Line(double a, double b, double c) {
        //根据 ax+by+c = 0 确定直线
        if(sgn(a) == 0) {
            s = Point(0, -c/b);
            e = Point(1, -c/b);
        } else if(sgn(b) == 0) {
            s = Point(-c/a, 0);
            e = Point(-c/a, 1);
        } else {
            s = Point(0, -c/b);
            e = Point(1, (-c-a)/b);
        }
    }
    void adjust() {
        if(e < s)	swap(s, e);
    }
    bool operator == (Line v) {
        return (s == v.s) && (e == v.e);
    }
    double length() {
        return s.distance(e);
    }
    double angle() {
        // 直线倾斜角
        double k = atan2(e.y-s.y, e.x-s.x);
        if(sgn(k) < 0)	k += pi;
        if(sgn(k-pi) == 0)	k -= pi;
        return k;
    }
    int relation(Point p) {
        /*
        判断直线和点关系
        this line, p point
        1	在左侧
        2	在右侧
        3	在直线上
        */
        int c = sgn((p-s) ^ (e-s));
        if(c < 0)	return 1;
        else if(c > 0)	return 2;
        else	return 3;
    }
    bool pointonseg(Point p) {
        /*
        判断点和线段关系
        this seg, p point
        0	不在线段上
        1	在线段上
        */
        return sgn((p-s) ^ (e-s)) == 0 && sgn((p-s) * (p-e)) <= 0;
    }
    bool parallel(Line v) {
        //判断两向量平行
        return sgn((e-s) ^ (v.e-v.s)) == 0;
    }
    int segcrossseg(Line v) {
        /*
        两线段关系
        2	规范相交
        1	不规范相交
        0	不相交
        */
        int d1 = sgn((e-s) ^ (v.s-s));
        int d2 = sgn((e-s) ^ (v.e-s));
        int d3 = sgn((v.e-v.s) ^ (s-v.s));
        int d4 = sgn((v.e-v.s) ^ (e-v.s));
        if((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s-s) * (v.s-e)) <= 0) ||
               (d2 == 0 && sgn((v.e-s) * (v.e-e)) <= 0) ||
               (d3 == 0 && sgn((s-v.s) * (s-v.e)) <= 0) ||
               (d4 == 0 && sgn((e-v.s) * (e-v.e)) <= 0);
    }
    int linecrossseg(Line v) {
        /*
        判断直线和线段关系
        this line, v seg
        2	规范相交
        1	非规范相交
        0	不相交
        */
        int d1 = sgn((e-s) ^ (v.s-s));
        int d2 = sgn((e-s) ^ (v.e-s));
        if((d1 ^ d2) == -2)	return 2;
        else	return (d1 == 0 || d2 == 0);
    }
    int linecrossline(Line v) {
        /*
        两直线关系
        0	平行
        1	重合
        2	相交
        */
        if((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }
    Point crosspoint(Line v) {
        //求两直线的交点
        //要求两直线不平行，不重合
        double a1 = (v.e-v.s) ^ (s-v.s);
        double a2 = (v.e-v.s) ^ (e-v.s);
        return Point((s.x*a2-e.x*a1), (s.y*a2-e.y*a1))/(a2-a1);
    }
    double dispointtoline(Point p) {
        //求点到直线的距离
        return fabs((p-s)^(e-s))/length();
    }
    double dispointtoseg(Point p) {
        if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }
    double dissegtoseg(Line v) {
        /*
        返回线段到线段的距离
        前提是两线段不相交，相交为0
        */
        return min(min(dispointtoseg(v.s), dispointtoseg(v.e)),
                   min(v.dispointtoseg(s), v.dispointtoseg(e)));
    }
    Point lineprog(Point p) {
        //返回点 p 在直线上的投影点
        return s + (((e-s)*((e-s)*(p-s))) / ((e-s).len2()));
    }
    Point symmetrypoint(Point p) {
        //返回点 p 关于直线p的对称点
        Point q = lineprog(p);
        return Point(2*q.x-p.x, 2*q.y-p.y);
    }
};

struct polygon {
    int n;
    Point p[maxn];
    Line l[maxn];
    void getline() {
        for(int i=1; i<=n; i++) {
            l[i] = Line(p[i], p[i%n+1]);
        }
    }
    struct cmp {
        //极角排序的比较函数
        Point p;
        cmp(Point _p) {
            p = _p;
        }
        bool operator()(Point _a, Point _b) const {
            Point a = _a, b = _b;
            int d = sgn((a-p) ^ (b-p));
            if(d == 0) {
                return sgn(a.distance(p) - b.distance(p)) < 0;
            } else {
                return d > 0;
            }
        }
    };
    void norm() {
        //极角排序
        int id = 1;
        for(int i=2; i<=n; i++) {
            if(p[i] < p[id])
                id = i;
        }
        swap(p[id], p[1]);
        sort(p+1, p+1+n, cmp(p[1]));
    }
    void Graham(polygon &convex) {	//引用
        //求解凸包
        //convex凸包
        norm();
        mes(convex.p, 0);
        int &top = convex.n = 0;	//引用
        if(n == 1) {
            convex.p[++top] = p[1];
        } else if(n == 2) {
            convex.p[++top] = p[1];
            convex.p[++top] = p[2];
            if(convex.p[1] == convex.p[2]) top--;
        } else {
            convex.p[++top] = p[1];
            convex.p[++top] = p[2];
            for(int i=3; i<=n; i++) {
                while(top>1 && sgn((convex.p[top]-convex.p[top-1]) ^ (p[i]-convex.p[top-1])) <= 0)
                    top--;
                convex.p[++top] = p[i];
            }
        }
    }
    bool isconvex() {
        //判断多边形是不是凸的
        bool s[2];
        mes(s, false);
        for(int i=1; i<=n; i++) {
            int j = i%n + 1;
            int k = j%n + 1;
            s[sgn((p[j]-p[i]) ^ (p[k]-p[i])) + 1] = true;
            if(s[0] && s[2])	return false;
        }
        return true;
    }
    int relationpoint(Point q) {
        /*
        点和多边形关系
        3	点上
        2	边上
        1	内部
        0	外部
        */
        for(int i=1; i<=n; i++) {
            if(p[i] == q) return 3;
        }
        getline();
        for(int i=1; i<=n; i++) {
            if(l[i].pointonseg(q))	return 2;
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            int j = i%n + 1;
            int k = sgn((q-p[j]) ^ (p[i]-p[j]));
            int u = sgn(p[i].y - q.y);
            int v = sgn(p[j].y - q.y);
            if(k > 0 && u < 0 && v >= 0)	cnt++;
            if(k < 0 && v < 0 && u >= 0)	cnt--;
        }
        return cnt != 0;
    }
    bool getdir() {
        //得到方向
        //1表示逆时针，0表示顺时针
        double sum = 0;
        for(int i=1; i<=n; i++) {
            sum += p[i] ^ p[i%n+1];
        }
        if(sgn(sum) > 0)	return 1;
        return 0;
    }
    Point getbarycentre() {
        //得到重心
        Point ans(0, 0);
        double area = 0;
        for(int i=2; i<=n-1; i++) {
            double tmp = (p[i]-p[1]) ^ (p[i+1]-p[0]);
            if(sgn(tmp) == 0)	continue;
            area += tmp;
            ans.x = (p[1].x + p[i].x + p[i+1].x) / 3 * tmp;
            ans.y = (p[0].y + p[i].y + p[i+1].y) / 3 * tmp;
        }
        if(sgn(area))	ans = ans / area;
        return ans;
    }
    double getperimeter() {
        //多边形的周长
        double ans = 0.0;
        if(n == 1) {
            return ans;
        } else if(n == 2) {
            ans += p[1].distance(p[2]);
        } else {
            for(int i=1; i<=n; i++) {
                ans += p[i].distance(p[i%n+1]);
            }
        }
        return ans;
    }
    double getarea() {
        //多边形面积
        double sum = 0;
        for(int i=1; i<=n; i++) {
            sum += (p[i] ^ p[i%n+1]);
        }
        return fabs(sum)/2.0;
    }
} po, convex;

int main() {
    scanf("%d%", &po.n);
    for(int i=1; i<=po.n; i++) {
        scanf("%lf%lf", &po.p[i].x, &po.p[i].y);
    }
    po.Graham(convex);
    double ans = convex.getarea();
    printf("%d\n", (int)(ans/50.0));
    return 0;
}
