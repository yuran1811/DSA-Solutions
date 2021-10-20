// https://cses.fi/problemset/task/1160
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5, LOG = 30;
 
int n, q, par[N][LOG + 1];
vector <int> Vst, d;
 
void Sparse_Table()
{
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	Vst.assign(n + 5, 0);
	d.assign(n + 5, 0);
	for (int i = 1; i <= n; i++) cin >> par[i][0];
}
 
void DFS(int v, int p)
{
	Vst[v] = --p;
	int u = par[v][0];
	if (!Vst[u]) DFS(u, p);
	if (Vst[u] < 0) Vst[v] = Vst[u] - Vst[v] + 1, d[v] = 0;
	else Vst[v] = Vst[u], d[v] = d[u] + 1;
}
 
int Jump(int u, int steps)
{
	for (int i = 0; i <= 30; i++)
		if (steps & (1 << i))
			u = par[u][i];
	return u;
}
 
int Solve()
{
	Load_Data();
	Sparse_Table();
	for (int i = 1; i <= n; i++) 
		if (!Vst[i]) DFS(i, 0);
	for (int i = 1, a, b; i <= q; i++, cout << '\n')
	{
		cin >> a >> b;
		if (d[b] <= d[a] && Jump(a, d[a] - d[b]) == b)
			cout << d[a] - d[b]; else
		if (d[b] < Vst[a] && Jump(a, d[a] + Vst[a] - d[b]) == b)
			cout << d[a] + Vst[a] - d[b];
		else cout << -1;
	}
	return 0;
}
 
int main() {Solve();}
