// https://cses.fi/problemset/task/2080
#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 5;
 
ll Vst[N], f[N], d[N] = {1};
ll res = 0, Max = 0;
vector <int> a[N];
int n, k;
 
int DFS(int u, int p)
{
	f[u] = 1;
	for (int v : a[u])
		if (v != p && !Vst[v])
			f[u] += DFS(v, u);
	return f[u];
}
 
int Calc(int u, int p, int n)
{
	for (int v : a[u])
		if (v != p && !Vst[v] && f[v] * 2 > n)
			return Calc(v, u, n);
	return u;
}
 
void Get(int u, int p, ll cnt, int ok)
{
	if (cnt > k) return;
	Max = max(Max, cnt);
	if (!ok) res += d[k - cnt];
	else d[cnt]++;
	for (int v : a[u])
		if (v != p && !Vst[v])
			Get(v, u, cnt + 1, ok);
}
 
void Process(int u)
{
	DFS(u, 0);
	int Centroid = Calc(u, 0, f[u]);
	Vst[Centroid] = 1; Max = 0;
	for (int v : a[Centroid])
		if (!Vst[v])
			Get(v, Centroid, 1, 0),
			Get(v, Centroid, 1, 1);
	fill(d + 1, d + Max + 1, 0);
	for (int v : a[Centroid])
		if (!Vst[v]) Process(v);
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
	Process(1);
	cout << res;
	return 0;
}
