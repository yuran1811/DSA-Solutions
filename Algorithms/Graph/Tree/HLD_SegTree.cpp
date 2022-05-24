#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;

int par[N], sz[N], d[N], heavy[N];
int pos[N], head[N], order = 0;
int n, q, val[N];

vector <int> a[N];

bool mxm(int &a, int b) { return a < b ? a = b, 1 : 0; }

struct SegTree
{
	int t[4 * N];

	void Up(int l, int r, int i, int pos, int val)
	{
		if (pos < l || r < pos) return;
		if (l == r) return void (t[i] = val);

		int m = (l + r) >> 1;
		Up(l, m, i << 1, pos, val);
		Up(m + 1, r, i << 1 | 1, pos, val);

		t[i] = max(t[i << 1], t[i << 1 | 1]);
	}

	int Get(int l, int r, int i, int u, int v)
	{
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return t[i];

		int m = (l + r) >> 1;
		return max(Get(l, m, i << 1, u, v), Get(m + 1, r, i << 1 | 1, u, v));
	}
} T;

void DFS(int u, int p)
{
	sz[u] = 1;
	int Max = 0;

	for (int v : a[u])
		if (v != p)
		{
			d[v] = d[u] + 1;
			par[v] = u;

			DFS(v, u);

			sz[u] += sz[v];

			if (mxm(Max, sz[v]))
				heavy[u] = v;
		}
}

void HLD(int u, int top)
{
	pos[u] = ++order;
	head[u] = top;

	T.Up(1, n, 1, pos[u], val[u]);

	if (heavy[u]) HLD(heavy[u], top);

	for (int v : a[u])
		if (v != par[u] && heavy[u] != v)
			HLD(v, v);
}

int MaxVal_UtoV(int u, int v)
{
	int res = 0;

	for (; head[u] != head[v]; v = par[head[v]])
	{
		if (d[head[u]] > d[head[v]]) swap(u, v);

		mxm(res, T.Get(1, n, 1, pos[head[v]], pos[v]));
	}

	if (d[u] > d[v]) swap(u, v);

	mxm(res, T.Get(1, n, 1, pos[u], pos[v]));

	return res;
}

void loadData()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);

	DFS(1, 0);
	HLD(1, 1);
}

int Solve()
{
	loadData();
	return 0;
}

int main() {Solve();}