#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

bool pri[16005];

void handle() {
	memset(pri, true, sizeof(pri));
	for(int i=2; i<=16000; i++) {
		if(pri[i]) {
			for(int j=2; i*j<=16000; j++) {
				pri[i*j] = false;
			}
		}
	}
	pri[1] = pri[2] = false;
}

int main() {
	int n;
	handle();
	int cas = 1;
	while(scanf("%d", &n), n){
		printf("%d: ", cas++);
		printf("%s\n", pri[n] ? "yes" : "no");
	}
	return 0;
}