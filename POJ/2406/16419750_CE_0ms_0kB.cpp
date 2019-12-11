#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2000005;
int wa[N], wb[N], ws[N], wv[N], sa[N * 3];
int rnk[N * 3], height[N * 3], s[N];
char str[N];

int c0(int *r, int a, int b) {
	return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

int c12(int k, int *r, int a, int b) {
	if (k == 2)
		return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
	return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}

void Rsort(int *r, int *a, int *b, int n, int m) {
	for (int i = 0; i < n; i++) wv[i] = r[a[i]];
	for (int i = 0; i < m; i++) ws[i] = 0;
	for (int i = 0; i < n; i++) ws[wv[i]]++;
	for (int i = 1; i < m; i++) ws[i] += ws[i - 1];
	for (int i = n - 1; i >= 0; i--) b[--ws[wv[i]]] = a[i];
}

void dc3(int *r, int *sa, int n, int m) {
	int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
	r[n] = r[n + 1] = 0;
	for (i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
	Rsort(r + 2, wa, wb, tbc, m);
	Rsort(r + 1, wb, wa, tbc, m);
	Rsort(r, wa, wb, tbc, m);
	for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
		rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
	if (p < tbc) dc3(rn, san, tbc, p);
	else for (i = 0; i < tbc; i++) san[rn[i]] = i;
	for (i = 0; i < tbc; i++) if (san[i] < tb) wb[ta++] = san[i] * 3;
	if (n % 3 == 1) wb[ta++] = n - 1;
	Rsort(r, wb, wa, ta, m);
	for (i = 0; i < tbc; i++) wv[wb[i] = G(san[i])] = i;
	for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
	for (; i < ta; p++) sa[p] = wa[i++];
	for (; j < tbc; p++) sa[p] = wb[j++];
}

void calheight(int *r, int *sa, int n) {
	int i, j, k = 0;
	for (i = 1; i <= n; i++) rnk[sa[i]] = i;
	for (i = 0; i < n; height[rnk[i++]] = k)
		for (k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

int main() {
	while (scanf("%s", str) == 1 && str[0] != '.') {
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			s[i] = str[i] - 'a' + 1;
		s[len] = 0;
		dc3(s, sa, len + 1, 105);
		calheight(s, sa, len);
		int aa = len - height[rnk[0]];
		int ans = 1;
		if (len % aa == 0) {
			ans = len / aa;
		}
		printf("%d\n", ans);
	}
	return 0;
}