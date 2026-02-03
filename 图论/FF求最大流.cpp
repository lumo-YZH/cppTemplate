#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define N 10020
using namespace std;

int n, m, inf = 0x7f7f7f;
bool book[N];
struct edge
{
	int v;
	int w;
	int rev; // 在反向边中存储的位置
};
vector<edge> e[N];
void add(int u, int v, int w) // 加边
{
	e[u].push_back(edge{v, w, e[v].size()});
	e[v].push_back(edge{u, 0, e[u].size() - 1});
}
int dfs(int s, int t, int f)
{
	if (s == t)
		return f; // 找到终点
	book[s] = true;
	for (int i = 0; i < e[s].size(); i++)
	{
		edge &G = e[s][i];
		if (G.w > 0 && book[G.v] == false)
		{
			int d = dfs(G.v, t, min(f, G.w)); // 两者之间流量较小的一个
			if (d > 0)
			{
				G.w -= d; // 改变正向边和反向边
				e[G.v][G.rev].w += d;
				return d;
			}
		}
	}
	return 0;
}

int FF(int s, int t) // O(nm^2)
{
	int ans = 0;
	while (1)
	{
		memset(book, false, sizeof(book)); // 每次找増广路
		int d = dfs(s, t, inf);
		if (d == 0) // 找不到增广路返回总流量
			return ans;
		ans += d;
	}
}

int main()
{
	int u, v, w;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			e[i].clear();
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
		}
		printf("%d\n", FF(1, n));
	}
	return 0;
}
