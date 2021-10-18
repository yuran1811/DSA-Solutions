// https://cses.fi/problemset/task/1139
#include <iostream>
#include <vector>
#include <set>
#define sz(s) (int (s.size()))
using namespace std;
 
const int N = 2e5 + 5;
 
int n, c[N], cnt[N];
vector <int> a[N];
set <int> f[N];
 
void DFS(int u, int p)
{
	f[u].insert(c[u]);
	for (int v : a[u])
	{
		if (v == p) continue;
		DFS(v, u);
		if (sz(f[u]) < sz(f[v]))
			swap(f[u], f[v]);
	}
 
	for (int v : a[u])
	{
		if (v == p) continue;
		for (int child : f[v])
			f[u].insert(child);
	}
	cnt[u] = sz(f[u]);
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 2, u, v; i <= n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
}
 
int Solve()
{
	Load_Data();
	DFS(1, 1);
	for (int i = 1; i <= n; i++)
		cout << cnt[i] << ' ';
	return 0;
}
 
int main() {Solve();}
