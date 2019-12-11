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

struct Circle {
    Point p;	//圆心
    double r;	//半径
    Circle() {}
    Circle(Point _p, double _r) {
        p = _p, r = _r;
    }
    Circle(double x, double y, double _r) {
        p = Point(x, y), r = _r;
    }
    Circle(Point a, Point b, Point c) {
        //求三角形的外接圆
        Line u = Line((a+b)/2, ((a+b)/2) + ((b-a).rotleft()));
        Line v = Line((b+c)/2, ((b+c)/2) + ((c-b).rotleft()));
        p = u.crosspoint(v);
        r = p.distance(a);
    }
    Circle(Point a, Point b, Point c, bool t) {
        //求三角形的内接圆
        //bool t用来区别三角形外接圆的函数
        Line u, v;
        double m = atan2(b.y-a.y, b.x-a.x);
        double n = atan2(c.y-a.y, c.x-a.x);
        u.s = a;
        u.e = u.s + Point(cos((n+m)/2), sin((n+m)/2));
        v.s = b;
        m = atan2(a.y-b.y, a.x-b.x);
        n = atan2(c.y-b.y, c.x-b.x);
        v.e = v.s + Point(cos((n+m)/2), sin((n+m)/2));
        p = u.crosspoint(v);
        r = Line(a, b).dispointtoseg(p);
    }
    bool operator == (Circle v) {
        return p==v.p && sgn(r-v.r)==0;
    }
    bool operator < (Circle v) {
        return (p<v.p) || (p==v.p && sgn(r-v.r)<0);
    }
    double area() {
        //面积
        return pi*r*r;
    }
    double cirperimeter() {
        //周长
        return 2*pi*r;
    }
    int relation(Point b) {
        /*
        点和圆的关系
        0	圆外
        1	圆上
        2	圆内
        */
        double dst = b.distance(p);
        if(sgn(dst-r) < 0)	return 2;
        else if(sgn(dst-r) == 0)	return 1;
        else return 0;
    }
    int relationseg(Line v) {
        /*
        线段和圆的关系
        0	圆外
        1	圆上
        2	圆内
        */
        double dst = v.dispointtoseg(p);
        if(sgn(dst-r) < 0)	return 2;
        else if(sgn(dst-r) == 0)	return 1;
        else return 0;
    }
    int relationline(Line v) {
        /*
        直线和圆的关系
        0	圆外
        1	圆上
        2	圆内
        */
        double dst = v.dispointtoline(p);
        if(sgn(dst-r) < 0)	return 2;
        else if(sgn(dst-r) == 0)	return 1;
        else return 0;
    }
    int relationcircle(Circle v) {
        /*
        两圆的关系
        5	相离
        4	外切
        3	相交
        2	内切
        1	内含
        */
        double d = p.distance(v.p);
        if(sgn(d-r-v.r) > 0)	return 5;
        if(sgn(d-r-v.r) == 0)	return 4;
        double l = fabs(r-v.r);
        if(sgn(d-r-v.r) < 0 && sgn(d-l) > 0)	return 3;
        if(sgn(d-l) == 0)		return 2;
        if(sgn(d-l) < 0)		return 1;
    }
    int pointcrosscircle(Circle v, Point &p1, Point &p2) {
        //求两个圆的交点，返回交点数
        int rel = relationcircle(v);
        if(rel == 1 || rel == 5)	return 0;
        double d = p.distance(v.p);
        double l = (d*d + r*r - v.r*v.r) / (2*d);
        double h = sqrt(r*r-l*l);
        Point tmp = p + (v.p-p).trunc(l);
        p1 = tmp + ((v.p-p).rotleft().trunc(h));
        p2 = tmp + ((v.p-p).rotright().trunc(h));
        if(rel == 2 || rel == 4)
            return 1;
        return 2;
    }
    int pointcrossline(Line v, Point &p1, Point &p2) {
        //求直线和圆的交点，返回交点数
        if(!(*this).relationline(v))	return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r*r-d*d);
        if(sgn(d) == 0) {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e-v.s).trunc(d);
        p2 = a - (v.e-v.s).trunc(d);
        return 2;
    }
    int getcircle(Point a, Point b, double r1, Circle &c1, Circle &c2) {
        //过a, b两点, 半径为 r1 的圆, 返回圆数
        Circle x(a, r1), y(b, r1);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if(!t)	return 0;
        c1.r = c2.r = r1;
        return t;
    }
    int getcircle(Line u, Point q, double r1, Circle &c1, Circle &c2) {
        //与直线 u 相切, 过点 q, 半径为 r1 的圆,返回圆数
        double dis = u.dispointtoline(q);
        if(sgn(dis-2*r1) > 0)	return 0;
        if(sgn(dis) == 0) {
            c1.p = q + ((u.e-u.s).rotleft().trunc(r1));
            c2.p = q + ((u.e-u.s).rotright().trunc(r1));
            c1.r = c2.r = r1;
            return 2;
        }
        Line u1 = Line((u.s + (u.e-u.s).rotleft().trunc(r1)), (u.e + (u.e-u.s).rotleft().trunc(r1)));
        Line u2 = Line((u.s + (u.e-u.s).rotright().trunc(r1)), (u.e + (u.e-u.s).rotright().trunc(r1)));
        Circle cc = Circle(q, r1);
        Point p1, p2;
        if(!cc.pointcrossline(u1, p1, p2))
            cc.pointcrossline(u2, p1, p2);
        c1 = Circle(p1, r1);
        if(p1 == p2) {
            c2 = c1;
            return 1;
        }
        c2 = Circle(p2, r1);
        return 2;
    }
    int getcircle(Line u, Line v, double r1, Circle &c1, Circle &c2, Circle &c3, Circle &c4) {
        //同时与直线u, v相切, 半径为 r1 的圆
        if(u.parallel(v))return 0;//两直线平行
        Line u1 = Line(u.s + (u.e-u.s).rotleft().trunc(r1),u.e + (u.e-u.s).rotleft().trunc(r1));
        Line u2 = Line(u.s + (u.e-u.s).rotright().trunc(r1),u.e + (u.e-u.s).rotright().trunc(r1));
        Line v1 = Line(v.s + (v.e-v.s).rotleft().trunc(r1),v.e + (v.e-v.s).rotleft().trunc(r1));
        Line v2 = Line(v.s + (v.e-v.s).rotright().trunc(r1),v.e + (v.e-v.s).rotright().trunc(r1));
        c1.r = c2.r = c3.r = c4.r = r1;
        c1.p = u1.crosspoint(v1);
        c2.p = u1.crosspoint(v2);
        c3.p = u2.crosspoint(v1);
        c4.p = u2.crosspoint(v2);
        return 4;
    }
    int getcircle(Circle cx, Circle cy, double r1, Circle &c1, Circle &c2) {
        //同时与不相交圆cx, cy相切，半径为 r1 的圆
        Circle x(cx.p, r1+cx.r), y(cy.p, r1+cy.r);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if(!t)	return 0;
        c1.r = c2.r = r1;
        return t;
    }
    int tangentline(Point q, Line &u, Line &v) {
        //过一点做圆的切线,求切线
        int x = relation(q);
        if(x == 2)return 0;
        if(x == 1) {
            u = Line(q, q + (q-p).rotleft());
            v = u;
            return 1;
        }
        double d = p.distance(q);
        double l = r*r/d;
        double h = sqrt(r*r-l*l);
        u = Line(q, p + ((q-p).trunc(l) + (q-p).rotleft().trunc(h)));
        v = Line(q, p + ((q-p).trunc(l) + (q-p).rotright().trunc(h)));
        return 2;
    }
    double areacircle(Circle v) {
        //两相交圆的面积
        int rel = relationcircle(v);
        if(rel >= 4)	return 0.0;
        if(rel <= 2)	return min(area(), v.area());
        double d = p.distance(v.p);
        double hf = (r+v.r+d)/2.0;
        double ss = 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
        double a1 = acos((r*r+d*d-v.r*v.r) / (2.0*r*d));
        a1 = a1*r*r;
        double a2 = acos((v.r*v.r+d*d-r*r) / (2.0*v.r*d));
        a2 = a2*v.r*v.r;
        return a1+a2-ss;
    }
    double areatriangle(Point a, Point b) {
        //求圆和三角形 pab 的相交面积
        if(sgn((p-a)^(p-b)) == 0)	return 0.0;
        Point q[5];
        int len = 0;
        q[len++] = a;
        Line l(a,b);
        Point p1,p2;
        if(pointcrossline(l,q[1],q[2]) == 2) {
            if(sgn((a-q[1])*(b-q[1])) < 0)	q[len++] = q[1];
            if(sgn((a-q[2])*(b-q[2])) < 0)	q[len++] = q[2];
        }
        q[len++] = b;
        if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1])) > 0)
            swap(q[1], q[2]);
        double res = 0;
        for(int i = 0; i < len-1; i++) {
            if(relation(q[i]) == 0 || relation(q[i+1]) == 0) {
                double arg = p.rad(q[i], q[i+1]);
                res += r*r*arg/2.0;
            } else {
                res += fabs((q[i]-p)^(q[i+1]-p)) / 2.0;
            }
        }
        return res;
    }
};

struct Polygon {
    int n;
    Point p[maxn];
    Line l[maxn];
    Polygon() {
        n = 0;
    }
    void add(Point q) {
        p[++n] = q;
    }
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
    void Graham(Polygon &convex) {	//引用
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
            if(top == 2 && convex.p[1] == convex.p[2])
                top--;
        }
    }
    bool isconvex() {
        //判断多边形是不是凸的
        //1是凸的 0不是凸的
        bool s[3];
        mes(s, false);
        for(int i=1; i<=n; i++) {
            int j = i%n + 1;
            int k = j%n + 1;
            s[sgn((p[j]-p[i]) ^ (p[k]-p[i])) + 1] = true;
            if(s[0] && s[2])	return false;
//			printf("%f\n", (p[j]-p[i]) ^ (p[k]-p[i]));
//			if(s[1] || s[0])	return true;
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
    void convexcut(Line u, Polygon &po) {
        //直线切割凸多边形左侧,注意直线方向
        int &top = po.n = 0;	//引用
        for(int i=1; i<=n; i++) {
            int d1 = sgn((u.e-u.s) ^ (p[i]-u.s));
            int d2 = sgn((u.e-u.s) ^ (p[i%n+1]-u.s));
            if(d1 >= 0)	po.p[++top] = p[i];
            if(d1*d2<0)	po.p[++top] = u.crosspoint(Line(p[i], p[i%n+1]));
        }
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
    double areacircle(Circle c) {
        //多边形和圆相交的面积
        double ans = 0;
        for(int i=1; i<=n; i++) {
            int j = i%n+1;
            if(sgn((p[j]-c.p) ^ (p[i]-c.p)) >= 0)
                ans += c.areatriangle(p[i], p[j]);
            else
                ans -= c.areatriangle(p[i], p[j]);
        }
        return fabs(ans);
    }
    int relationcircle(Circle c) {
        /*
        多边形和圆的关系
        2	圆完全在多边形内
        1	圆在多边形内，但是碰到了多边形边界
        0	其他
        */
        getline();
        int x = 2;
        if(relationpoint(c.p) != 1)	return 0;
        for(int i=1; i<=n; i++) {
            if(c.relationseg(l[i]) == 2)	return 0;
            if(c.relationseg(l[i]) == 1)	x = 1;
        }
        return x;
    }
};

int main() {
	while(scanf("%d", &n), n) {
		Polygon po;
		for(int i=1; i<=n; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			po.add(Point(x, y));
		}
		printf("%s\n", po.isconvex() ? "convex" : "concave");
	}
    return 0;
}
