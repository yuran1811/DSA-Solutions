#include <bits/stdc++.h>

using namespace std;

struct Dinic 
{
	vector <int> to, nxt, capa, f;
	vector <int> head, d, use;
	int lim;
 
	void init(int n) 
	{
		head.assign(n + 5, -1);
		d.assign(n + 5, 0);
		use.assign(n + 5, 0);
		// to.clear(); nxt.clear(); capa.clear(); f.clear();
	}
 
	int addEdge(int u, int v, int c, bool r = false) 
	{
		to.push_back(v);
		nxt.push_back(head[u]);
		capa.push_back(c);
		f.push_back(0);

		head[u] = to.size() - 1;

		to.push_back(u);
		nxt.push_back(head[v]);
		capa.push_back(c * r);
		f.push_back(0);
		
		head[v] = to.size() - 1;
		return head[u];
	}
 
	bool BFS(int s, int t) 
	{
		fill(d.begin(), d.end(), -1);
		queue <int> q;

		d[s] = 0; 
		q.push(s);

		while (q.size()) 
		{
			s = q.front(); q.pop();
			for (int i = head[s]; i >= 0; i = nxt[i])
				if (d[to[i]] < 0 && capa[i] - f[i] >= lim)
					d[to[i]] = d[s] + 1, q.push(to[i]);
		}

		return d[t] >= 0;
	}
 
	int DFS(int s, int t, int flow) 
	{
		if (s == t) return flow;

		for (int &i = use[s]; i >= 0; i = nxt[i])
			if (d[to[i]] == d[s] + 1 && capa[i] - f[i] >= lim) 
			{
				int d = DFS(to[i], t, min(flow, capa[i] - f[i]));

				if (d > 0) 
				{
					f[i] += d; 
					f[i ^ 1] -= d; 
					return d;
				}
			}
		return 0;
	}
 
	long long dinic(int s, int t) 
	{
		long long maxflow = 0; int aug;

		for (lim = 1 << 30; lim > 0; lim >>= 1)
			while (BFS(s, t)) 
			{
				copy(head.begin(), head.end(), use.begin());

				while ((aug = DFS(s, t, INT_MAX)) > 0)
					maxflow += aug;
			}

		return maxflow;
	}
} D;

int main() 
{
	int n, m;
	cin >> n >> m;

	D.init(n);

	for (int i = 1, u, v, c; i <= m; i++)
		cin >> u >> v >> c, D.addEdge(u, v, c, 1);

	cout << D.dinic(1, n);

	return 0;
}