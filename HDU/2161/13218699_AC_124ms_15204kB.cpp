#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn=1e7;
bool ispri[maxn];
int pri[maxn/10];
int tol=0;

void handle() {
	memset(ispri, true, sizeof(ispri));
	memset(pri, 0, sizeof(pri));
	for(int i=2; i<maxn; i++) {
		if(ispri[i])
			pri[tol++] = i;
		for(int j=0; j<tol && i*pri[j]<maxn; j++) {
			ispri[i*pri[j]] = false;
			if(i % pri[j] == 0)
				break;
		}
	}
	ispri[1] = ispri[2] = false;

}

int main() {
	int n;
	handle();
	int cas = 1;
	while(scanf("%d", &n) && n>0) {
		if(ispri[n])
			printf("%d: yes\n", cas++);
		else
			printf("%d: no\n", cas++);
	}
	return 0;
}
