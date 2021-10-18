// https://cses.fi/problemset/task/1137
#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 5;
 
vector <int> a[N];
int n, q, val[N];
int NumChild[N];
int Order[N], t;
 
struct BIT
{
	vector <ll> bit;
	void Init(int n) {bit.assign(n + 5, 0);}
	void Up(int i, ll val) {for (; i <= n; i += -i & i) bit[i] += val;}
	ll Get(int i)
	{
		ll res = 0;
		for (; i > 0; i -= -i & i) 
			res += bit[i];
		return res;
	}
	void GetAns(int u) {cout << Get(NumChild[u] + Order[u] - 1) - Get(Order[u] - 1) << '\n';}
} T;
 
void DFS(int u, int p)
{
	Order[u] = ++t;
	NumChild[u] = 1;
	for (int v : a[u])
		if (v != p) DFS(v, u),
			NumChild[u] += NumChild[v];
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q; T.Init(n);
	for (int u = 1; u <= n; u++) cin >> val[u];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);		
}
 
int Solve()
{
	Load_Data();
	DFS(1, -1);
	for (int u = 1; u <= n; u++)
		T.Up(Order[u], val[u]);
 
	for (int i = 1, c, u, v; i <= q; i++)
	{
		cin >> c >> u;
		if (c == 2) T.GetAns(u); else
		cin >> v, T.Up(Order[u], v - val[u]), val[u] = v;
	}
	return 0;
}
 
int main() {Solve();}
