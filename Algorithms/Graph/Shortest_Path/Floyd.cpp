#include <iostream>

using namespace std;

const int N = 1e3;
const int oo = 1e9 + 7;

int n, m, q, a[N][N], t[N][N];

void loadGraph()
{
	cin >> n >> m >> q; 
	for (int i = 1, u, v, w; i <= m; i++)
	{
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
		t[u][v] = v;
		t[v][u] = u;
	}
}

void Init()
{
	for (int i = 1; i <= n; i++)
	{
		a[i][i] = 0;
		for (int j = 1; j <= n; j++)
			a[i][j] = oo;
	}
}

void Floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j], t[i][j] = t[i][k];
}

int main()
{
	Init();
	loadGraph();
	Floyd();
	return 0;
}
