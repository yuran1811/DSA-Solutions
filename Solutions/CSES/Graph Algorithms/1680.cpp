// https://cses.fi/problemset/task/1680
#include <bits/stdc++.h>
#define NoWay {cout << "IMPOSSIBLE"; exit(0);}
using namespace std;
 
const int N = 2e5 + 5;
 
int n, m, Cycle, Is_Vs[N], Trace[N];
vector <int> a[N], Topo, f, res;
 
int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
 
void DFS(int u)
{
	Is_Vs[u] = 2;
	if (Cycle) return;
	for (int v : a[u])
	{
		if (Is_Vs[v] == 1) continue;
		if (Is_Vs[v] == 2) {Cycle = 1; return;}
		DFS(v);
	}
	Is_Vs[u] = 1;
	Topo.push_back(u);
}
 
void Topo_Sort()
{
	Cycle = 0;
	for (int u = 1; u <= n; u++)
	{
		if (Cycle) break;
		if (!Is_Vs[u]) DFS(u);
	}
	reverse(Topo.begin(), Topo.end());
}
 
void Find_MaxD()
{
	f.assign(n + 1, 0); f[1] = 1;
	Trace[1] = -1;
	bool ok = false;
	for (int u : Topo)
	{
		if (u == 1) ok = true;
		if (!ok) continue;
		for (int v : a[u])
			if (mxm(f[v], f[u] + 1))
				Trace[v] = u;
	}
	if (!f[n]) NoWay;
	for (int v = n; v > 0; v = Trace[v]) res.push_back(v);
	if (res.back() != 1) NoWay;
}
 
void Prt_Paths()
{
	reverse(res.begin(), res.end());
	cout << f[n] << '\n';
	for (int v : res) cout << v << " ";
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
	Find_MaxD();
	Prt_Paths();
	return 0;
}
 
int main() {Solve();}
