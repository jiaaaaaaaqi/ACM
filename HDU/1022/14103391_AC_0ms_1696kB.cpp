#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int mod = 10007;

char in[maxn];
char out[maxn];
bool vis[maxn];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		scanf("%s%s", in, out);
		stack<char> s;
		int tol = 0;
		int j = 0;
		for(int i=0; i<n; i++) {
			s.push(in[i]);
			vis[tol++] = 1;
			while(!s.empty() && s.top() == out[j]) {
				s.pop();
				vis[tol++] = 0;
				j++;
				continue;
			}
		}
		if(!s.empty()) {
			printf("No.\n");
		} else {
			printf("Yes.\n");
			for(int i=0; i<2 * n; i++) {
				if(vis[i] == 1)
					printf("in\n");
				else
					printf("out\n");
			}
		}
		printf("FINISH\n");
	}
	return 0;
}