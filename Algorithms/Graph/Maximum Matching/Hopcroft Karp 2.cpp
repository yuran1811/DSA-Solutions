#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7, oo = Me9 +ing;

int d[N], used[N], cnt, match[N];
vector <int> a[N];
int n, m, u, v;
bool vs[N];

bool BFS() 
{
	queue <int> q;
	
	for (int u = 1; u <= n; u++) 
	{
		if (used[u] == cnt) d[u] = -1;
		else d[u] = 0, q.push(u);
		vs[u] = 0;
	}

	while (q.size()) 
	{
		int u = q.front(); q.pop();
		for (int v: a[u]) 
			if (!match[v]) return true; else 
			if (d[match[v]] < 0)
				d[match[v]] = d[u] + 1, q.push(match[v]);
	}

	return false;
}

bool DFS(int u) 
{
	if (!m) return true;
	
	vs[u] = true;
	
	for (int v: a[u]) 
	{
		int _u = match[v];
		if (!match[v] || (!vs[_u] && d[_u] == d[u] + 1 && DFS(_u))) 
		{
			if (!match[v]) m--;
			
			used[u] = cnt;
			match[v] = u;

			return true;
		}
	}

	return false;
}

void Matching() 
{
	int job = m;

	while (m) 
	{
		cnt++;

		while (BFS()) 
		{
			for (int u = 1; u <= n; u++)
				if (used[u] != cnt) DFS(u);

			if (!m) break;
		}
	}
	
	cout << cnt << '\n';
	for (int i = 1; i <= job; i++)
		cout << match[i] << " ";
}

int main()
{
	cin >> n >> m;
	while (cin >> u >> v)
		a[u].push_back(v);
	
	Matching();

	return 0;
}