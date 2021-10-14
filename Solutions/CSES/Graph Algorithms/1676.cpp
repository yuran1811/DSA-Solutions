// https://cses.fi/problemset/task/1676
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
const int N = 1e5 + 5;
 
int n, m, f[N], par[N];
 
int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
 
int Root(int u) {return par[u] == u ? u : par[u] = Root(par[u]);}
 
void Mer(int u, int v, int &Num, int &CntCpn)
{
	u = Root(u), v = Root(v);
	if (u == v) return;
	if (f[u] < f[v]) swap(u, v);
	f[u] += f[v];
	par[v] = u;
	CntCpn--;
	mxm(Num, f[u]);
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		par[i] = i, f[i] = 1;
}
 
int Solve()
{
	Load_Data();
	int CntCpn = n, Num = 1;
	for (int i = 1, u, v; i <= m; i++)
	{
		cin >> u >> v;
		Mer(u, v, Num, CntCpn);
		cout << CntCpn << " " << Num << '\n';
	}
	return 0;
}
 
int main() {Solve();}
