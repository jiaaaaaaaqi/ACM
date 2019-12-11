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
const int    maxn = 1e2 + 10;
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
    bool operator == (Point a) const {
        return sgn(x-a.x) == 0 && sgn(y-a.y) == 0;
    }
    bool operator < (Point a) const {
        return sgn(x-a.x) == 0 ? sgn(y-a.y)<0 : x<a.x;
    }
    Point operator - (Point a) const {
        return Point(x-a.x, y-a.y);		//向量减
    }
    Point operator + (Point a) const {
        return Point(x+a.x, y+a.y);		//向量加
    }
    double operator * (Point a) const {	//点乘(内积)
        return x*a.x + y*a.y;
    }
    double operator ^ (Point a) const {	//叉乘(外积)
        return x*a.y - y*a.x;
    }
    Point operator * (double k) const {
        return Point(x*k, y*k);
    }
    Point operator / (double k) const {
        return Point(x/k, y/k);
    }
    Point trunc(double r) {
        //化为长度为 r 的向量
        double l = length();
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
    double length() {			//向量长度
        return hypot(x, y);
    }
    double length2() {			//向量长度平方
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
        s = _s, e = _e;
    }
    double length() {
        return s.distance(e);
    }
    int linecrossseg(Line v) {
        /*
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
}line[maxn];

bool ok(Line l) {
	if(sgn(l.length()) == 0)	return false;
	for(int i=1; i<=n; i++) {
		int tmp = l.linecrossseg(line[i]);
		if(tmp == 0)	return false;
	}
	return true;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%lf%lf%lf%lf", &line[i].s.x, &line[i].s.y, &line[i].e.x, &line[i].e.y);
		}
		if(n <= 2) {
			printf("Yes!\n");
			continue;
		}
		bool flag = false;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(ok(Line(line[i].s, line[j].s)))	flag = true;
				if(ok(Line(line[i].s, line[j].e)))	flag = true;
				if(ok(Line(line[i].e, line[j].s)))	flag = true;
				if(ok(Line(line[i].e, line[j].e)))	flag = true;
				if(flag)	break;
			}
			if(flag)	break;
		}
		printf("%s\n", flag ? "Yes!" : "No!");
	}
	return 0;
}
