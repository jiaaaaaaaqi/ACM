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
const int    maxn = 30;
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
    Point operator - (Point a) {
        return Point(x-a.x, y-a.y);		//向量减
    }
    double operator * (Point a) {	//点乘(内积)
        return x*a.x + y*a.y;
    }
    double operator ^ (Point a) {	//叉乘(外积)
        return x*a.y - y*a.x;
    }
    Point rotleft() {
        //原向量逆时针旋转90度
        return Point(-y, x);
    }
    Point rotright() {
        //原向量顺时针旋转90度
        return Point(y, -x);
    }
};

struct Line {
    Point s, e;
    Line() {};
    Line(Point _s, Point _e) {
        // 两点确定直线
        s = _s, e = _e;
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
};

struct Polygon {
    int n;
    char id;
    Point p[maxn];
    Line l[maxn];
    Polygon() {
        n = 0;
    }
    void init() {
		n = 0;
		mes(p, 0), mes(l, 0);
    }
    void add(Point q) {
        p[++n] = q;
    }
    void getline() {
        for(int i=1; i<=n; i++) {
            l[i] = Line(p[i], p[i%n+1]);
        }
    }
    bool operator < (Polygon x) const {
		return id < x.id;
    }
} po[maxn];
vector<char> vv[maxn];

void solve(char *s, Polygon &p) {
    double x1, x2, x3, x4;
    double y1, y2, y3, y4;
	p.init();
    if(s[1] == 's') {
		scanf(" (%lf,%lf)", &x1, &y1);
		scanf(" (%lf,%lf)", &x3, &y3);
		Point O((x1+x3)/2.0, (y1+y3)/2.0);
		Point O2 = Point(Point(x1, y1) - O).rotright();
		Point O4 = Point(Point(x1, y1) - O).rotleft();
		x2 = O2.x + O.x, y2 = O2.y + O.y;
		x4 = O4.x + O.x, y4 = O4.y + O.y;
		p.add(Point(x1, y1));
		p.add(Point(x2, y2));
		p.add(Point(x3, y3));
		p.add(Point(x4, y4));
    } else if(s[1] == 'r') {
		scanf(" (%lf,%lf)", &x1, &y1);
		scanf(" (%lf,%lf)", &x2, &y2);
		scanf(" (%lf,%lf)", &x3, &y3);
		x4 = x1 + x3 - x2;
		y4 = y1 + y3 - y2;
		p.add(Point(x1, y1));
		p.add(Point(x2, y2));
		p.add(Point(x3, y3));
		p.add(Point(x4, y4));
    } else if(s[1] == 'l') {
        for(int i=1; i<=2; i++) {
            scanf(" (%lf,%lf)", &x1, &y1);
            p.add(Point(x1, y1));
        }
    } else if(s[1] == 't') {
        for(int i=1; i<=3; i++) {
            scanf(" (%lf,%lf)", &x1, &y1);
            p.add(Point(x1, y1));
        }
    } else if(s[1] == 'p') {
        int t;
        scanf("%d", &t);
        for(int i=1; i<=t; i++) {
            scanf(" (%lf,%lf)", &x1, &y1);
            p.add(Point(x1, y1));
        }
    }
    p.getline();
}

bool ok(Polygon p1, Polygon p2) {
	for(int i=1; i<=p1.n; i++) {
		for(int j=1; j<=p2.n; j++) {
			if(p1.l[i].segcrossseg(p2.l[j])) {
				return true;
			}
		}
	}
	return false;
}

int main() {
    char s1[20], s2[20];
    mes(s1, 0);
    mes(s2, 0);
    while(scanf("%s", s1+1), s1[1]!='.') {
        scanf("%s", s2+1);
		for(int i=0; i<maxn; i++)
			vv[i].clear();
        n = 0;
        po[++n].id = s1[1];
        solve(s2, po[n]);
        while(1) {
            scanf("%s", s1+1);
            if(s1[1] == '-')	break;
            scanf("%s", s2+1);
            po[++n].id = s1[1];
            solve(s2, po[n]);
        }
//        for(int i=1; i<=n; i++) {
//			printf("%d %c\n", i, po[i].id);
//			for(int j=1; j<=po[i].n; j++) {
//				printf("%f %f\n", po[i].p[j].x, po[i].p[j].y);
//			}
//        }
		sort(po+1, po+1+n);
        for(int i=1; i<n; i++) {
            for(int j=i+1; j<=n; j++) {
                if(ok(po[i], po[j])) {
                    vv[i].push_back(po[j].id);
                    vv[j].push_back(po[i].id);
                }
            }
        }
        for(int i=1; i<=n; i++) {
			if(vv[i].size() == 0) {
				printf("%c has no intersections\n", po[i].id);
			} else {
				sort(vv[i].begin(), vv[i].end());
				if(vv[i].size() == 1) {
					printf("%c intersects with %c\n", po[i].id, vv[i][0]);
				} else if(vv[i].size() == 2) {
					printf("%c intersects with %c and %c\n", po[i].id, vv[i][0], vv[i][1]);
				} else {
					printf("%c intersects with ", po[i].id);
					for(int j=0; j<vv[i].size()-1; j++)
						printf("%c, ", vv[i][j]);
					printf("and %c\n", vv[i][vv[i].size()-1]);
				}
			}
        }
        printf("\n");
    }
    return 0;
}
