// https://cses.fi/problemset/task/1675
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
const int N = 2e5 + 5, oo = 2e9 + 7;
 
int n, m, tmp;
long long res = 0;
 
struct E
{
	int u, v, w;
	bool operator <(const E &x) const {return w < x.w;}
} a[N];
 
struct DSU
{
	int f[N];
 
	void init(int n) {for (int i = 1; i <= n; i++) f[i] = -1;}
	int rt(int u) {return f[u] < 0 ? u : f[u] = rt(f[u]);}
	bool kt(int u, int v) {return rt(u) == rt(v);}
	void mer(int u, int v)
	{
		if (kt(u, v)) return;
		int ru = rt(u), rv = rt(v);
		if (f[ru] > f[rv]) swap(ru, rv);
		f[ru] += f[rv];
		f[rv] = ru;
	}
} dsu;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; dsu.init(n);
    for (int i = 1; i <= m; i++)
    	cin >> a[i].u >> a[i].v >> a[i].w;
    sort(a + 1, a + 1 + m);
 
    tmp = n;
    for (int i = 1; i <= m; i++)
    	if (!dsu.kt(a[i].u, a[i].v)) 
    	{
    		res += a[i].w, dsu.mer(a[i].u, a[i].v), tmp--;
    	}
    if (tmp > 1) cout << "IMPOSSIBLE";
    else cout << res;
	return 0;
}
