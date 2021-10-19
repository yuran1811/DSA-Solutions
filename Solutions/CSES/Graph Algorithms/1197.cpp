// https://cses.fi/problemset/task/1197
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
const int N = 3e3 + 5, oo = 2e9 + 7;
 
int n, m, tmp;
long long res = 0, d[N];
vector <int> f(N, -1), cycle;
 
struct G {int u, v, w;};
vector <G> a;
 
void findd()
{	
	int x;
	for (int i = 1; i <= n; i++)
	{
		x = -1;
		for (G j : a)
			if (d[j.v] > d[j.u] + j.w)
				d[j.v] = d[j.u] + j.w, f[j.v] = j.u, x = j.v;
	}
	if (x == -1) cout << "NO"; else
	{
		for (int i = 1; i <= n; i++)
			x = f[x];
		for (int v = x;; v = f[v])
		{
			cycle.push_back(v);
			if (v == x && int (cycle.size()) > 1) break;
		}
		reverse(cycle.begin(), cycle.end());
		cout << "YES\n";
		for (int i : cycle) cout << i << " ";
	}
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
        cin >> u >> v >> w, a.push_back({u, v, w});
    findd();
    return 0;
}
