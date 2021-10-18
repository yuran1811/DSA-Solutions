// https://cses.fi/problemset/task/1138
#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 5;
 
int sz[N], par[N], head[N];
int n, q, pos[N], val[N];
int Order = 0, Node[N];
 
vector <int> a[N];
 
bool mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
 
struct SegTree
{
	ll t[4 * N];
 
	void Up(int l, int r, int i, int pos, int val)
	{
		if (pos < l || r < pos) return;
		if (l == r) return void (t[i] = val);
		int m = (l + r) >> 1;
		Up(l, m, i << 1, pos, val);
		Up(m + 1, r, i << 1 | 1, pos, val);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}
 
	ll Get(int l, int r, int i, int u, int v)
	{
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return t[i];
		int m = (l + r) >> 1;
		return Get(l, m, i << 1, u, v) + Get(m + 1, r, i << 1 | 1, u, v);
	}
} T;
 
void DFS(int u, int p)
{
	par[u] = p;
	sz[u] = 1;
	for (int v : a[u])
	{
		if (v == p) continue;
		DFS(v, u);
		sz[u] += sz[v];
	}
}
 
void HLD(int u, int top)
{
	pos[u] = ++Order;
	Node[Order] = u;
	head[u] = top;
 
	int spe_vertex = -1, isFound = -1;
	for (int v : a[u])
	{
		if (v == par[u] || !mxm(isFound, sz[v])) continue;
		spe_vertex = v;
	}
 
	if (isFound < 0) return;
	HLD(spe_vertex, top);
	for (int v : a[u])
	{
		if (v == par[u] || v == spe_vertex) continue;
		HLD(v, v);
	}
}
 
ll Tracing(int u)
{
	ll res = 0;
	for (; head[u] != -1; u = par[head[u]])
		res += T.Get(1, n, 1, pos[head[u]], pos[u]);
	res += T.Get(1, n, 1, 1, pos[u]);
	return res;
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int u = 1; u <= n; u++) cin >> val[u];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
}
 
int Scorpio()
{
	Load_Data();
	DFS(1, -1);
	HLD(1, -1);
	for (int u = 1; u <= n; u++)
		T.Up(1, n, 1, pos[u], val[u]);
 
	for (int i = 1, u, v, c; i <= q; i++)
	{
		cin >> c >> u;
		if (c ^ 2) cin >> v, T.Up(1, n, 1, pos[u], v);
		else cout << Tracing(u) << '\n';
	}
	return 0;
}
 
int main() {Scorpio();}
