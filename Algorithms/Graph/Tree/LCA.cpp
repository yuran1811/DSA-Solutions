const int N = 1e5 + 5, LOG = 20; 

void DFS(int u, int p)
{
	for (pair <int, int> x : a[u])
	{
		int v = x.first;
		int w = x.second;
		if (v == p) continue;
		high[v] = high[u] + 1;
		d[v] = d[u] + w;
		par[v] = u;
		DFS(v, u);
	}
}

void Sparse_Table()
{
	DFS(1, 0);
	high[0] = -1;
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

void LCA(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = LOG; i >= 0; i--)
		if (high[par[u][i]] >= high[v])
			u = par[u][i];
	if (u == v) return u;
	
	for (int i = LOG; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i],
			v = par[v][i];
	return par[u][0];
}
