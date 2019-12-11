/*
          .
         ';;;;;.
        '!;;;;;;!;`
       '!;|&#@|;;;;!:
      `;;!&####@|;;;;!:
     .;;;!&@$$%|!;;;;;;!'.`:::::'.
     '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
     :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`    '!%&#########@$!:.
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
    :;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:                 !@#$'
      |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:              '%%!%&;
      |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`            '%$|!%&;
      |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:           .|%;:!&%`
      !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;          `%&%!!$&:
      '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;         !$!;:!$&:
       |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'      `%$|%%;|&$'
        |&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
        `%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
        !&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
       '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
       .!%%&%'`|$;       :|$#%|@#&;%#%.
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
const int    maxn = 2e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];
vector<int> sg(maxn, -1);
vector<int> vv;

void handle() {
	sg[0] = 0;
	sg[1] = sg[2] = sg[3] = 1;
	for(int i=4; i<=200; i++) {
		vector<bool> vis(maxn, false);
		for(int j=1; j<=i; j++) {
			int ans = 0;
			if(j-3 >= 0)	ans ^= sg[j-3];
			if(i-j-2 >= 0)	ans ^= sg[i-j-2];
			vis[ans] = true;
		}
		for(int j=0; ; j++) {
			if(!vis[j]) {
				sg[i] = j;
				break;
			}
		}
	}
}

bool check() {
	bool flag = false;
	int len = strlen(s+1);
	for(int i=1; i<=len; i++) {
		if(i>=3) {
			if(s[i-2]=='X' && s[i-1]=='X')
				vv.push_back(i), flag = true;
		}
		if(i+2<=len) {
			if(s[i+1]=='X' && s[i+2]=='X')
				vv.push_back(i), flag = true;
		}
		if(i>1 && i+1<=len) {
			if(s[i-1]=='X' && s[i+1]=='X')
				vv.push_back(i), flag = true;
		}
	}
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	return flag;
}

bool solve(int x, int len) {
	if(s[x] == 'X')	return 0;
	s[x] = 'X';
//	printf("%s\n", s+1);
	for(int i=1; i<len; i++) {
		if(s[i]=='X' && s[i+1]=='X') {
			s[x] = '.';
			return false;
		}
	}
	for(int i=1; i<len-1; i++) {
		if(s[i]=='X' && s[i+2]=='X') {
			s[x] = '.';
			return false;
		}
	}
	bool f = false;
	int ans = 0;
	int last = 1;
	for(int i=1; i<=len; i++) {
		if(s[i] == 'X') {
			if(f) {
				int tmp = i - last - 4;
				if(tmp >= 0)
					ans ^= sg[tmp];
			} else {
				int tmp = i - last - 2;
				f = true;
				if(tmp >= 0)
					ans ^= sg[tmp];
			}
			last = i+1;
		}
	}
	int tmp = len + 1 - last - 2;
	if(tmp >= 0)
		ans ^= sg[tmp];
	s[x] = '.';
	return ans == 0;
}

int main() {
	cas = 1;
    handle();
//    for(int i=1; i<=100; i++)	printf("%d %d\n", i, sg[i]);
    scanf("%d", &T);
    while(T--) {
		vv.clear();
		scanf("%s", s+1);
		printf("Case %d: ", cas++);
		if(check()) {
			for(int i=0; i<vv.size(); i++) {
				printf("%d%c", vv[i], i==vv.size()-1 ? '\n' : ' ');
			}
		} else {
			int len = strlen(s+1);
			for(int i=1; i<=len; i++) {
				if(solve(i, len))	
					vv.push_back(i);
			}
			if(vv.size() == 0) {
				printf("0\n");
			} else {
				for(int i=0; i<vv.size(); i++) {
					printf("%d%c", vv[i], i==vv.size()-1 ? '\n' : ' ');
				}
			}
		}
    }
    return 0;
}
