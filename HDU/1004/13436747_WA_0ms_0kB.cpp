#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

map<string, int> m;

int main() {
	int n;
	while(scanf("%d", &n), n) {
		string str;
		int ans = 0;
		string res;
		for(int i=0; i<n; i++) {
			cin >> str;
			m[str]++;
			if(m[str] > ans)
				res = str;
		}
		cout << res << endl;
	}
	return 0;
}