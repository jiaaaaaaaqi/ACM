#include<stdio.h>
#include<string.h>
#include<math.h>

int n,m,area=0,ans;
int minv[22]={0};
int mins[22]={0};

int premaxarea(int N, int r, int h) {
	int v=0;
	for(int i=0; i<N; i++) {
		v += (r-i) * (r-i) * (h-i);
	}
	return v;
}

int ca=0;
void dfs(int v,int N, int r, int h) {
	if(N==0) {
		if(v)
			return ;
		else {
			ans=ans<area ? ans:area;
			return ;
		}
	}
	if(v <= 0)
		return ;
	if(minv[N] > v)
		return ;
	if(area+mins[N] >= ans)
		return ;
	if(r<N || h<N)
		return ;
	if(premaxarea(N, r, h) < v)
		return ;

	for(int i=r; i>=N; i--) {
		if(N==m)
			area = i*i;
		for(int j=h; j>=N; j--) {
			area += 2*i*j;
			dfs(v-i*i*j, N-1, i-1, j-1);
			area -= 2*i*j;
		}
	}
}

int main() {
	scanf("%d%d",&n, &m);
	minv[0]=0;
	mins[0]=0;
	for(int i=1; i<=m; i++) {
		minv[i] = minv[i-1] + i*i*i;
		mins[i] = mins[i-1] + 2*i*i;
	}
	if(minv[m] > n)
		printf("0\n");
	else {
		int maxh= (n-minv[m-1]) / (m*m) +1;
		int maxr= sqrt((double)(n-minv[m-1]) / m) +1;
		area=0;
		ans=999999999;
		dfs(n, m, maxr, maxh);
		if(ans == 999999999)
			printf("0\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}