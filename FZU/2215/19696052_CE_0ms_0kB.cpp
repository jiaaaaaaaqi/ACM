#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const int mx = 10100;
const double eps = 1e-8;
const int mod = 1e9+7;
char str[mx], tmp[mx];

struct NUM {
    int x[505];
    int maxx;
};

struct Node {
    NUM num;
    int type;
    char symbol;
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
            
            suf[pos++] = Node{tmp_num, 1, ' '};

            tmp_num.x[0] = 0;
            tmp_num.x[1] = 0;
        }

        if (isSymbol(s[i])) {
            while (top > 0 && level(tmp[top-1]) >= level(s[i]) && tmp[top-1] != '(') suf[pos++] = Node{tmp_num, 2, tmp[top-1]}, top--;
            tmp[top++] = s[i];
        }
        else if (s[i] == '(')
            tmp[top++] = s[i];

        if (s[i] == ')') {
            while (tmp[top-1] != '(') suf[pos++] = Node{tmp_num, 2, tmp[top-1]}, top--;
            top--;
        }
    }

    //if (num > -eps) suf[pos++] = Node{num, 1, ' '};
    while (top > 0) suf[pos++] = Node{tmp_num, 2, tmp[top-1]}, top--;
    return pos;
}

NUM cal(NUM a, NUM b, char op) {
//	printf("a : ");
//	for(int i=0; i<=a.maxx; i++) {
//		printf("%d%c", a.x[i], i==a.maxx ? '\n' : ' ');
//	}
//	printf("b : ");
//	for(int i=0; i<=b.maxx; i++) {
//		printf("%d%c", b.x[i], i==b.maxx ? '\n' : ' ');
//	}
//	printf("op : %c\n", op);
    if (op == '+') {
        int maxlen = max(a.maxx, b.maxx);
        for(int i=a.maxx+1; i<=maxlen; i++) {
			a.x[i] = 0;
        }
        for(int i=b.maxx+1; i<=maxlen; i++) {
			b.x[i] = 0;
        }

//		printf("a : ");
//		for(int i=0; i<=a.maxx; i++) {
//			printf("%d%c", a.x[i], i==a.maxx ? '\n' : ' ');
//		}
//		printf("b : ");
//		for(int i=0; i<=b.maxx; i++) {
//			printf("%d%c", b.x[i], i==b.maxx ? '\n' : ' ');
//		}        

        NUM ans;
        for (int i = 0; i < maxlen; i++) ans.x[i] = 0;
        ans.maxx = maxlen;
        for (int i = 0; i <= maxlen; i++) ans.x[i] = (a.x[i] + b.x[i]) % mod;
//		printf("ans : ");
//		for(int i=0; i<=ans.maxx; i++) {
//			printf("%d%c", ans.x[i], i==ans.maxx ? '\n' : ' ');
//		}
        return ans;
    }
    else if (op == '*') {

        NUM ans;
        //printf("cal:%d %d %d %d\n", a.x[0], a.x[1], b.x[0], b.x[1]);
        for(int i=0; i<=a.maxx + b.maxx ;i++)   ans.x[i] = 0;
        for (int i = 0; i <= a.maxx; i++) {
            for (int j = 0; j <= b.maxx; j++) {
                ans.x[i+j] += a.x[i]*b.x[j] % mod;
                ans.x[i+j] %= mod;
            }
        }
       // printf("res:%d %d %d \n", ans.x[0], ans.x[1], ans.x[2]);
        ans.maxx = a.maxx + b.maxx;
//		printf("ans : ");
//		for(int i=0; i<=ans.maxx; i++) {
//			printf("%d%c", ans.x[i], i==ans.maxx ? '\n' : ' ');
//		}
        return ans;
    }
}

void calc(int len) {
    int top = 0;
    for (int i = 0; i < len; i++) {
        if (suf[i].type == 1) stack[top++] = suf[i];
        else {
            NUM ans = cal(stack[top-2].num, stack[top-1].num, suf[i].symbol);
//			printf("ans : ");
//			for(int i=0; i<=ans.maxx; i++) {
//				printf("%d%c", ans.x[i], i==ans.maxx ? '\n' : ' ');
//			}
            
            top -= 2;
            stack[top++] = Node{ans, 1, ' '};
        }
    }
}

int main() {
	int T;
	scanf("%d", &T);
    while (T--) {
		scanf("%s", str);
//        if (strlen(str) == 1 && str[0] == '0') break;
        int len = suffix(str);
//        printf("len = %d\n", len);
//        
//        for (int i = 0; i < len; i++)
//            if (suf[i].type == 1) {
//                if (suf[i].num.x[1] == 1) printf("x");
//                else printf("%d", suf[i].num.x[0]);
//            }
//            else printf("%c ", suf[i].symbol);
//        putchar('\n');
        
        calc(len);
       // printf("%.2f\n", stack[0].num);
       //puts("ok");
       bool flag = false;
       for (int i = stack[0].num.maxx; i >= 0; i--) {
           if (stack[0].num.x[i] != 0) flag = true;
           if (flag) printf ("%d%c", stack[0].num.x[i], i==0 ? '\n' : ' ');
       }
        
    }
    return 0;
}
/*
1
x*((1+x)*(1+x*x+x+5)+1*x*x)
*/
