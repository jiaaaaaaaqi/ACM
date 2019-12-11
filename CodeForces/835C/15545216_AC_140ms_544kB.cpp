#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e5+10;
int ans[110][110][15];
int res;

int main()
{
	int n, q, c;
	while(~scanf("%d%d%d", &n, &q, &c))
	{
		memset(ans, 0, sizeof(ans));
		
		for(int i = 1; i <= n; i++)
		{
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c); 
			ans[x][y][c] ++;
		}
		//预处理跑一遍，ans[x][y][k] => 从坐标(1,1)到坐标(x,y)亮度为 K 的点有 ans 个 	
		for(int i = 1; i <= 105; i++)
			for(int j = 1; j <= 105; j++)
				for(int k = 0; k <= 12; k++)
					ans[i][j][k] = ans[i][j][k] + ans[i][j-1][k] + ans[i-1][j][k] - ans[i-1][j-1][k];
		
		while(q--)
		{
			res = 0;
			int t, x1, x2, y1, y2;
			scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
			for(int i = 0; i <= c; i++)
			{
				int z = (t + i) % (c+1);
				int temp = ans[x2][y2][i] - ans[x1-1][y2][i] - ans[x2][y1-1][i] + ans[x1-1][y1-1][i];
				res += z*temp;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}