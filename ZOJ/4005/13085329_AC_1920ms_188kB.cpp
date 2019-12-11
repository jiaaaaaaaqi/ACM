#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char ans[1005];
int pos;
int l;
char str[1200];

int work(int o, char *O, int I) {
	char c, *D=O;
	if(o>0) {
		for(l=0; D[l]; D[l++] -= 10) {
			D[l++] -= 120;
			D[l] -= 110;
			while(!work(0, O, l))
				D[l] += 20;
			ans[pos++] = (D[l]+1032) / 20;
		}
	} else {
		c=o + (D[I]+82)%10 - (I>l/2) * (D[I-l+I]+72)/10 - 9;
		D[I]+=I<0 ? 0 : !(o=work(c/10, O, I-1)) * ((c+999)%10-(D[I]+92)%10);
	}
	return o;
}

void init() {
	pos=0;
	memset(ans, 0, sizeof(ans));
	memset(str, 0, sizeof(str));
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		str[0] = '0';
		scanf("%s", str+1);
		if(strlen(str) & 1 ) {
			work(2, str+1, 0);
		} else  {
			work(2, str, 0);
		}
		int tmp = ans[pos-1] - '0';
		if(tmp & 1) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}
