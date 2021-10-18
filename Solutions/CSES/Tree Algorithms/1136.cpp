// https://cses.fi/problemset/task/1136
#include <iostream>
#include <vector>
using namespace std;
 
const int N = 2e5 + 5, LOG = 18;
 
vector <int> a[N];
int par[N][LOG + 5];
int n, m, Cnt[N];
int high[N];
 
void DFS(int u)
{
	for (int v : a[u])
		if (v != par[u][0])
		{
			high[v] = high[u] + 1;
			par[v][0] = u;
			DFS(v);
		}
}
 
void Sparse_Table()
{
	DFS(1); high[0] = -1;
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}
 
int LCA(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = LOG; i >= 0; i--)
		if (high[par[u][i]] >= high[v])
			u = par[u][i];
	if (u == v) return u;
 
	for (int i = LOG; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i],
			v = par[v][i];
	return par[u][0];
}
 
void Calc(int u, int p)
{
	for (int v : a[u])
		if (v != p) Calc(v, u), Cnt[u] += Cnt[v];
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);		
}
 
int Solve()
{
	Load_Data();
	Sparse_Table();
	for (int i = 1, u, v, A; i <= m; i++)
	{
		cin >> u >> v;
		A = LCA(u, v);
		Cnt[u]++; Cnt[v]++;
		Cnt[par[A][0]]--;
		Cnt[A]--;
	}
	Calc(1, -1);
	for (int i = 1; i <= n; i++)
		cout << Cnt[i] << " ";
	return 0;
}
 
int main() {Solve();}
