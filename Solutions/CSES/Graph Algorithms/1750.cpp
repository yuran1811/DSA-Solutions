// https://cses.fi/problemset/task/1750
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, LOG = 30;

int n, m, f[N][LOG + 1];

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> f[i][0];
}

int Solve()
{
	Load_Data();
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];

	for (int i = 1, u, v, k; i <= m; i++)
	{
		cin >> u >> k;
		v = 0;
		while (k)
		{
			if (k & 1) u = f[u][v];
			k >>= 1; v++;
		}
		cout << u << '\n';
	}
	return 0;
}

int main() {Solve();}
