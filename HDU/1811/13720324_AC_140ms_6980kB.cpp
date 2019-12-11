#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

const int maxn = 100005;

int n, m;
struct Node {
	int u, v;
	char ch;
};
Node node[2 * maxn];
int fa[maxn];
vector<int> v[maxn];
int degree[maxn];

void init(int n) {
	for(int i=0; i<n; i++) {
		fa[i] = i;
		v[i].clear();
	}
	memset(node, 0, sizeof(node));
	memset(degree, 0, sizeof(degree));
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool bind(int u, int v) {
	int x = find(u);
	int y = find(v);
	if(x == y)
		return false;
	else {
		fa[x] = y;
		return true;
	}
}

void topu(int sum) {
	queue<int> q;
	bool flag = false;
	for(int i=0; i<n; i++) {
		if(degree[i] == 0 && find(i) == i) {
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty()) {
		cnt++;
		if(q.size() > 1)
			flag = true;
		int top = q.front();
		q.pop();
		int len = v[top].size();
		for(int i=0; i<len; i++) {
			degree[v[top][i]]--;
			if(degree[v[top][i]] == 0) {
				q.push(v[top][i]);
			}
		}
	}
	if(cnt < sum) {
		printf("CONFLICT\n");
	} else if(flag) {
		printf("UNCERTAIN\n");
	} else {
		printf("OK\n");
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init(n);
		int sum = n;
		for(int i=0; i<m; i++) {
			int u, v;
			char ch[5];
			scanf("%d %s %d", &u, ch, &v);
			node[i].u = u;
			node[i].v = v;
			node[i].ch = ch[0];
			if(ch[0] == '=') {
				if(bind(u, v))
					sum--;
			}
		}
		for(int i=0; i<m; i++) {
			if(node[i].ch == '=')
				continue;
			int x = find(node[i].u);
			int y = find(node[i].v);
			if(node[i].ch == '>') {
				v[x].push_back(y);
				degree[y]++;
			} else if(node[i].ch == '<') {
				v[y].push_back(x);
				degree[x]++;
			}
		}
		topu(sum);
	}
	return 0;
}
