#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 200005;

__int128 a[mx];

inline bool read(__int128 &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')? -1:1;
    ret=(c=='-')?0:(c - '0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c - '0');
    ret*=sgn;
    return 1;
}

void output(__int128 ans) {
	if(ans > 9)	output(ans/10);
	putchar(ans%10+'0');
}


int main() {
    a[0] = 2; a[1] = 4;
    __int128 b = 1000000000000000;
    for (int i = 2; i <= 10000; i++) {
        a[i] = a[i-1]*4 - a[i-2];
        // printf("a[%d] = ", i);
        // output(a[i]);
        // puts("");
        if (a[i] > b*b) {
            //printf("cnt = %d\n", i);
            break;
        }
    }
    int T;
    scanf("%d", &T);

    while (T--) {
        __int128 N;
        read(N);
        for (int i = 1; i <= 53; i++) {
            if (a[i] >= N) {
                output(a[i]);
                puts("");
                break;
            }
        }
    }
    return 0;
}
