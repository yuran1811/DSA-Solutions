#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m;

struct DSU
{
	vector <int> f;
	void Init(int n) { f.resize(n + 5, -1); }
	int  Root(int u) { return f[u] < 0 ? u : f[u] = Root(f[u]); }
	bool Mer(int u, int v)
	{
		u = Root(u), v = Root(v);
		if (u == v) return false;
		if (f[u] > f[v]) swap(u, v);
		return f[u] += f[v], f[v] = u, 1;
	}
} dsu;

struct Edge
{
	int u, v, w;
	bool operator < (const Edge &a) const { return w < a.w; }
} e[N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + 1 + m);

	dsu.Init(n);
	long long res = 0;
	for (int i = 1; i <= m; i++)
		if (dsu.Mer(e[i].u, e[i].v))
			res += e[i].w;
	cout << res;

	return 0;
}