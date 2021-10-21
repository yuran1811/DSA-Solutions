// https://cses.fi/problemset/task/1681
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, MOD = 1e9 + 7;

vector <int> a[N], Topo, kt;
int n, m, Cycle = 0;

int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}

void DFS(int u)
{
	kt[u] = 2;
	for (int v : a[u])
	{
		if (kt[v] == 2) {Cycle = 1; return;}
		if (kt[v] == 1) continue;
		DFS(v); 
	}
	kt[u] = 1;
	Topo.push_back(u);
}

void Topo_Sort()
{
	kt.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (Cycle) break;
		if (!kt[i]) DFS(i);
	}
	reverse(Topo.begin(), Topo.end());
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, a[u].push_back(v);
}

int Solve()
{
	Load_Data();
	Topo_Sort();
	vector <int> f(n + 1, 0);
	f[1] = 1;
	for (int u : Topo)
		for (int v : a[u]) f[v] = (f[v] % MOD + f[u] % MOD) % MOD;
	cout << f[n];
	return 0;
}

int main() {Solve();}
