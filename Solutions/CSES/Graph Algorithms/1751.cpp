// https://cses.fi/problemset/task/1751
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
int n, a[N];
vector <bool> inC(N, false);
vector <int> f(N, 0), d(N, 0), adj[N];
 
int findd(int u, int p)
{
	if (f[u]) return f[u] == p ? u : 0;
	f[u] = p;
	return findd(a[u], p);
}
 
void dfs(int u)
{
	for (int v : adj[u])
		if (!inC[v])
			d[v] = d[u] + 1, dfs(v);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
    	cin >> a[i], adj[a[i]].push_back(i);
 
    for (int i = 1; i <= n; i++)
    	if (!f[i])
    	{
    		int x = findd(i, i);
	    	vector <int> c;
	    	while (f[x] == i)
	    		c.push_back(x),
	    		f[x] += n,
	    		x = a[x];
 
	    	for (int j : c)
	    		inC[j] = true,
	    		d[j] = int (c.size());
	    }
 
	for (int i = 1; i <= n; i++) 
		if (inC[i]) 
			dfs(i);
	for (int i = 1; i <= n; i++) 
		cout << d[i] << " ";
	return 0;
}
