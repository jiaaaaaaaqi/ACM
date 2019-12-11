#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e4+10;

struct Point {
	ll x, y;
	int id;
} p[maxn], be[maxn];
int n, m;
int ans[maxn];

int cmp1(Point a, Point b) {
	ll d = a.x*b.y - b.x*a.y;
	if(d == 0) {
		return a.x<b.x;
	} else {
		return d>0;
	}
}
int Qua(Point a) {
	if(a.x>0 && a.y>=0)	return 1;
	if(a.x<=0 && a.y>0)	return 2;
	if(a.x<0 && a.y<=0)	return 3;
	if(a.x>=0 && a.y<0)	return 4;
}

int cmp(Point a, Point b) {
	if(Qua(a) == Qua(b))	return cmp1(a, b);
	else	return Qua(a)<Qua(b);
}

ll check(Point a, Point b) {
	return a.x*b.x + a.y*b.y;
}

ll chaji(Point a, Point b) {
	return a.x*b.y - b.x*a.y;
}

ll work(Point pp) {
	for(int i=1; i<=n; i++) {
		p[i] = be[i];
		p[i].x -= pp.x;
		p[i].y -= pp.y;
	}
	p[0] = pp;
	sort(p+1, p+1+n, cmp);
	for(int j=1; j<=n; j++) {
		p[j+n] = p[j];
	}
	ll ans = 0;
	int R = 2;
	for(int L=1; L<=n; L++) {
		while(R<=2*n) {
			if(chaji(p[L], p[R]) < 0)	break;
			if(check(p[L], p[R]) <= 0)	break;
			R++;
		}
		int tR = R;
		while(tR<=2*n) {
			if(chaji(p[L], p[tR]) <= 0)	break;
			if(check(p[L], p[tR]) != 0)	break;
			ans++;
			tR++;
		}
	}
	return ans;
}

int main(){
	// freopen("in", "r", stdin);
	while(~scanf("%d%d", &n, &m)) {
		int all = 0;
		for(int i=1; i<=n; i++) {
			all++;
			int x, y;
			scanf("%d%d", &x, &y);
			p[all].x = x, p[all].y = y, p[all].id = 0;
			be[all] = p[all];
		}
		for(int i=1; i<=m; i++) {
			all++;
			int x, y;
			scanf("%d%d", &x, &y);
			p[all].x = x, p[all].y = y, p[all].id = i;
			be[all] = p[all];
			ans[i] = work(p[all]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=all; j++) {
				p[j] = be[j];
			}
			p[0] = be[i];
			int flag = 0;
			for(int j=1; j<=all; j++) {
				if(p[j].x == p[0].x && p[j].y == p[0].y)	flag = 1;
				if(flag)	p[j] = p[j+1];
				p[j].x -= p[0].x;
				p[j].y -= p[0].y;
			}

			int nn = all-1;
			sort(p+1, p+1+nn, cmp);
			for(int j=1; j<=nn; j++) {
				p[j+nn] = p[j];
			}
			int R = 2;
			for(int L=1; L<=nn; L++) {
				int id = 0;
				if(p[0].id)	id = p[0].id;
				if(p[L].id)	id = p[L].id;
				while(R<=2*nn) {
					if(chaji(p[L], p[R]) < 0)	break;
					if(check(p[L], p[R]) <= 0)	break;
					R++;
				}
				int tR = R;
				while(tR<=2*nn) {
					if(chaji(p[L], p[tR]) <= 0)	break;
					if(check(p[L], p[tR]) != 0)	break;
					if(id == 0)	{
						if(p[tR].id)	ans[p[tR].id]++;
					} else {
						if(p[tR].id == 0)	ans[id]++;
					}
					tR++;
				}
			}
		}
		for(int i=1; i<=m; i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}

