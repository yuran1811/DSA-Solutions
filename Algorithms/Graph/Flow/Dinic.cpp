#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 1080, oo = 1e9 + 7;

int d[N], c[N][N], f[N][N];
int dfs[N], cnt = 0;
int n, m, s, t;

vector <int> a[N];

bool BFS(int s, int t) 
{
	memset(d, 0, sizeof d);
	queue <int> q;

	d[s] = 1;
	q.push(s);

	while (q.size()) 
	{
		int u = q.front(); q.pop();
		if (u == t) return true;
		
		for (int v : a[u])
			if (!d[v] && f[u][v] < c[u][v])
				d[v] = d[u] + 1, q.push(v);
	}

	return false;
}

int DFS(int u, int t, int minn) 
{
	if (u == t) return minn;

	if (dfs[u] != cnt) dfs[u] = cnt;
	else return 0;

	for (int v : a[u])
		if (f[u][v] < c[u][v])
			if (dfs[v] != cnt && d[v] == d[u] + 1)
				if (int x = DFS(v, t, min(minn, c[u][v] - f[u][v]))) 
					return f[u][v] += x, f[v][u] -= x, x;

	return 0;
}

int main() 
{
	cin >> n >> m >> s >> t;
	for (int i = 1, u, v, w; i <= m; i++) 
		cin >> u >> v >> w,
		a[u].push_back(v),
		a[v].push_back(u),
		c[u][v] += w;

	int maxflow = 0;
	while (BFS(s, t))
		while (int x = (cnt++, DFS(s, t, oo)))
			maxflow += x;
	cout << maxflow;

	return 0;
}