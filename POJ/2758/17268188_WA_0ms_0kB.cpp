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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int len;
int a[maxn];
int sa[maxn];
int tp[maxn];
int rk[maxn];
char s[maxn];
int tax[maxn];
int cnt[maxn];
int height[maxn];
int dp[maxn][20];

void init() {
	mes(dp, 0);
	mes(height, 0);
}

void rsort(int n, int m) {
	for(int i=0; i<=m; i++)		tax[i] = 0;
	for(int i=1; i<=n; i++)		tax[rk[tp[i]]]++;
	for(int i=1; i<=m; i++)		tax[i] += tax[i-1];
	for(int i=n; i>=1; i--)		sa[tax[rk[tp[i]]]--] = tp[i];
}

int cmp(int *f, int x, int y, int w) {
	return f[x] == f[y] && f[x+w] == f[y+w];
}

void SA(int *a, int n, int m) {
	for(int i=1; i<=n; i++)		rk[i] = a[i], tp[i] = i;
	rsort(n, m);
	for(int i, p=1, w=1; p<n; w<<=1, m=p) {
		for(i=n-w+1, p=0; i<=n; i++)		tp[++p] = i;
		for(i=1; i<=n; i++)	if(sa[i] > w)	tp[++p] = sa[i] - w;
		rsort(n, m), swap(rk, tp);
		rk[sa[1]] = p = 1;
		for(i=2; i<=n; i++)		rk[sa[i]] = cmp(tp, sa[i], sa[i-1], w) ? p : ++p;
	}
	int j, k=0;
	for(int i=1; i<=n; height[rk[i++]] = k) 
		for(k = k ? k-1 : k, j = sa[rk[i]-1]; a[i+k] == a[j+k]; k++);
}

void debug(int n) {
	printf("a : ");
	for(int i=1; i<=n; i++)
		printf("%d%c", a[i], i==n ? '\n' : ' ');
	printf("sa : ");
	for(int i=1; i<=n; i++)
		printf("%d%c", sa[i], i==n ? '\n' : ' ');
	printf("height : ");
	for(int i=1; i<=n; i++)
		printf("%d%c", height[i], i==n ? '\n' : ' ');
}

void RMQ_INIT(int n) {
	for(int i=1; i<=n; i++)
		dp[i][0] = height[i];
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i<=n; i++) {
			if(i + (1<<j) - 1 <= n) {
				dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
			}
		}
	}
}

int RMQ_QUERY(int l, int r) {
	l = rk[l];
	r = rk[r];
	if(l > r)	swap(l, r);
	l++;
	int k = log(r - l + 1) / log(2.0);
	return min(dp[l][k], dp[r-(1<<k)+1][k]);
}

void update(int pos, int val) {
	for(int i=pos; i<=n; i+=lowbit(i))
		cnt[i] += val;
}

int query(int pos) {
	int ans = 0;
	for(int i=pos; i>=1; i-=lowbit(i))
		ans += cnt[i];
	return ans;
}

int ask(int x, int y) {
	int l = query(x);
	int r = query(y);
	return RMQ_QUERY(l, r);
}

void rebuild(int x, int pos) {
	int ans = 1;
	if(pos <= len) {
		int l = 1;
		int r = n;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(query(mid) >= pos) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		update(ans, 1);
	} else {
		update(len+1, 1);
	}
	for(int i=len; i>=pos; i--)
		a[i+1] = a[i];
	a[pos] = x;
	len++;
	init();
	SA(a, len, 255);
	RMQ_INIT(len);
}

int main() {
	init();
	mes(cnt, 0);
	scanf("%s", s+1);
	n = strlen(s+1);
	len = n;
	for(int i=1; s[i]!='\0'; i++) {
		a[i] = s[i];
		update(i, 1);
	}
	SA(a, len, 255);
	RMQ_INIT(len);
	int mm;
	scanf("%d", &mm);
	char id[5], x[5];
	int l, r;
	while(mm--) {
		scanf("%s", id+1);
		if(id[1] == 'Q') {
			scanf("%d%d", &l, &r);
			int ans = ask(l, r);
			printf("%d\n", ans);
		} else {
			scanf("%s%d", x+1, &l);
			rebuild(x[1], l);
		}
	}
	return 0;
}

/*
abaab
2
I a 6
Q 1 3
*/
