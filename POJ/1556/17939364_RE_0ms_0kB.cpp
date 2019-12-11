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
int np, nl;
int cas, tol, T;

int sgn(double x) {
    if(fabs(x) <= eps)	return 0;
    return x > 0 ? 1 : -1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) {
        x = _x, y = _y;
    }
    Point operator - (Point a) {
        return Point(x-a.x, y-a.y);
    }
    double operator * (Point a) {
        return x*a.x + y*a.y;
    }
    double operator ^ (Point a) {
        return x*a.y - a.x*y;
    }
    double distance(Point v) {
		return hypot(x-v.x, y-v.y);
    }
} point[maxn];

struct Line {
    Point s, e;
    Line() {}
    Line(Point _s, Point _e) {
        s = _s;
        e = _e;
    }
    double length() {
		return s.distance(e);
    }
    int segcrossseg(Line v) {
        int d1 = sgn((e-s) ^ (v.s-s));
        int d2 = sgn((e-s) ^ (v.e-s));
        int d3 = sgn((v.e-v.s) ^ (s-v.s));
        int d4 = sgn((v.e-v.s) ^ (e-v.s));
        if((d1^d2) == -2 && (d3^d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s-s) * (v.s-e)) <= 0) ||
               (d2 == 0 && sgn((v.e-s) * (v.e-e)) <= 0) ||
               (d3 == 0 && sgn((s-v.s) * (s-v.e)) <= 0) ||
               (d4 == 0 && sgn((e-v.s) * (e-v.e)) <= 0);
    }
} line[maxn];
vector<int> vv[20];
bool vis[maxn];
double dis[maxn];

void init() {
    np = nl = 0;
    for(int i=1; i<=10; i++) {
        vv[i].clear();
    }
}

void makemap() {
    for(int i=1; i<=np; i++) {
        for(int j=i+1; j<=np; j++) {
			if(point[i].x == point[j].x)	continue;
            Line l(point[i], point[j]);
            bool flag = true;
            for(int k=1; k<=nl; k++) {
                if(l.segcrossseg(line[k]) == 2) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                vv[i].push_back(j);
            }
        }
    }
}

double dijkstra(int st, int ed) {
	for(int i=0; i<=ed; i++) {
		dis[i] = 1.0 * inf;
	}
	mes(vis, 0);
	dis[st] = 0.0;
	vis[st] = true;
	for(int i=0; i<vv[1].size(); i++) {
		int v = vv[1][i];
		dis[v] = min(dis[v], dis[1] + Line(point[1], point[v]).length());
	}
	for(int r=2; r<=np; r++) {
		int p = 0;
		for(int i=1; i<=np; i++) {
			if(dis[p] > dis[i] && !vis[i]) {
				p = i;
			}
		}
		vis[p] = true;
		for(int i=0; i<vv[p].size(); i++) {
			int v = vv[p][i];
			if(!vis[v])
				dis[v] = min(dis[v], dis[p] + Line(point[p], point[v]).length());
		}
	}
	return dis[ed];
}

int main() {
    while(scanf("%d", &m), m!=-1) {
        point[++np] = Point(1, 6);
        for(int i=1; i<=m; i++) {
            double x, y1, y2, y3, y4;
            scanf("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
            x += 1.0, y1 += 1.0, y2 += 1.0, y3 += 1.0, y4 += 1.0;
            point[++np] = Point(x, y1);
            point[++np] = Point(x, y2);
            point[++np] = Point(x, y3);
            point[++np] = Point(x, y4);
            line[++nl] = Line(Point(x, 0), Point(x, y1));
            line[++nl] = Line(Point(x, y2), Point(x, y3));
            line[++nl] = Line(Point(x, y4), Point(x, 10));
        }
        point[++np] = Point(11, 6);
        makemap();
//        for(int i=1; i<=10; i++) {
//			for(auto j : vv[i]) {
//				printf("%f %f %f %f\n", point[i].x, point[i].y, point[j].x, point[j].y);
//			}
//        }
        double ans = dijkstra(1, np);
        printf("%.2f\n", ans);
    }
    return 0;
}
