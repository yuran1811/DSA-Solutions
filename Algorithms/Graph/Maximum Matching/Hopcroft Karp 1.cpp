#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 50, oo = 2e9 + 7;

vector <int> mx(N, 0), my(N, 0);
vector <int> a[N], d(N);
int n, m, p, Matched = 0;

bool BFS()
{
	queue <int> q; 
	for (int u = 1; u <= n; u++)
		if (mx[u]) d[u] = oo; else
		d[u] = 0, q.push(u);

	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : a[u])
			if (!my[v]) return true; else 
			if (d[my[v]] == oo)
				d[my[v]] = d[u] + 1, q.push(my[v]);
	}

	return false;
}

bool DFS(int u)
{
	if (d[u] == oo) return false;

	for (int v : a[u])
		if (!my[v] || (d[my[v]] == d[u] + 1 && DFS(my[v])))
			return mx[u] = v, my[v] = u, true;

	return false;
}

void Matching()
{
	while (BFS())
		for (int u = 1; u <= n; u++)
			if (!mx[u]) Matched += DFS(u);

	cout << Matched;
}

int main()
{
	cin >> n >> m >> p; 
	for (int i = 1, u, v; i <= p; i++)
		cin >> u >> v, a[u].push_back(v);

	Matching();

	return 0;
}