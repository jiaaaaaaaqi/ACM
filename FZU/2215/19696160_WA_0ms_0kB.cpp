#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const int mx = 3100;
const double eps = 1e-8;
const int mod = 1e9+7;
char str[mx], tmp[mx];

struct NUM {
    ll x[505];
    int maxx;
};

struct Node {
    NUM num;
    int type;
    char symbol;
    Node() {}
    Node(NUM _num, int _type, int _symbol) {
		for(int i=0; i<=_num.maxx; i++) {
			num.x[i] = _num.x[i];
		}
		num.maxx = _num.maxx;
		type = _type;
		symbol = _symbol;
    }
}suf[mx], stack[mx];

bool isSymbol(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int level(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else return 3;
}

int suffix(char s[]) {
    int len = strlen(s);
    int pos = 0, top = 0;
    NUM tmp_num;
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9' || s[i] == 'x') {
            if (s[i] == 'x') tmp_num.x[0] = 0, tmp_num.x[1] = 1,tmp_num.maxx = 1;
            else tmp_num.x[0] = s[i]-'0', tmp_num.maxx = 0;
            
            suf[pos++] = Node(tmp_num, 1, ' ');

            tmp_num.x[0] = 0;
            tmp_num.x[1] = 0;
        }

        if (isSymbol(s[i])) {
            while (top > 0 && level(tmp[top-1]) >= level(s[i]) && tmp[top-1] != '(') suf[pos++] = Node(tmp_num, 2, tmp[top-1]), top--;
            tmp[top++] = s[i];
        }
        else if (s[i] == '(')
            tmp[top++] = s[i];

        if (s[i] == ')') {
            while (tmp[top-1] != '(') suf[pos++] = Node(tmp_num, 2, tmp[top-1]), top--;
            top--;
        }
    }
    while (top > 0) suf[pos++] = Node(tmp_num, 2, tmp[top-1]), top--;
    return pos;
}

NUM cal(NUM a, NUM b, char op) {
    if (op == '+') {
        int maxlen = max(a.maxx, b.maxx);
        for(int i=a.maxx+1; i<=maxlen; i++) {
			a.x[i] = 0;
        }
        for(int i=b.maxx+1; i<=maxlen; i++) {
			b.x[i] = 0;
        }
        NUM ans;
        for (int i = 0; i < maxlen; i++) ans.x[i] = 0;
        ans.maxx = maxlen;
        for (int i = 0; i <= maxlen; i++) ans.x[i] = (a.x[i] + b.x[i]) % mod;
        return ans;
    }
    else if (op == '*') {
        NUM ans;
        for(int i=0; i<=a.maxx + b.maxx ;i++)   ans.x[i] = 0;
        for (int i = 0; i <= a.maxx; i++) {
            for (int j = 0; j <= b.maxx; j++) {
                ans.x[i+j] += a.x[i]*b.x[j] % mod;
                ans.x[i+j] %= mod;
            }
        }
        ans.maxx = a.maxx + b.maxx;
        return ans;
    }
}

void calc(int len) {
    int top = 0;
    for (int i = 0; i < len; i++) {
        if (suf[i].type == 1) stack[top++] = suf[i];
        else {
            NUM ans = cal(stack[top-2].num, stack[top-1].num, suf[i].symbol);
            top -= 2;
            stack[top++] = Node(ans, 1, ' ');
        }
    }
}

int main() {
	int T;
	scanf("%d", &T);
    while (T--) {
		scanf("%s", str);
        int len = suffix(str);
        calc(len);
       bool flag = false;
       for (int i = stack[0].num.maxx; i >= 0; i--) {
           if (stack[0].num.x[i] != 0) flag = true;
           if (flag) printf ("%lld%c", stack[0].num.x[i], i==0 ? '\n' : ' ');
       }
        
    }
    return 0;
}
/*
1
x*((1+x)*(1+x*x+x+5)+1*x*x)
*/
