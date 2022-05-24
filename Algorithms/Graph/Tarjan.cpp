#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

vector <int> Node[N], a[N], s;
int Num[N], Low[N], cnt = 0;
int n, m, NumCpn;

int mnz(int &a, int b) { return a > b ? a = b, 1 : 0; }

void Tarjan(int u)
{
	Num[u] = Low[u] = ++cnt;
	s.push_back(u);

	for (int v : a[u])
		if (!Num[v])
		{
			Tarjan(v);
			mnz(Low[u], Low[v]);
		}
		else mnz(Low[u], Num[v]);

	if (Low[u] == Num[u])
	{
		NumCpn++;
		int v;
		
		do
		{
			v = s.back(); s.pop_back();
			Node[NumCpn].push_back(v);
			Num[v] = Low[v] = oo;
		} while (v != u);

		sort(Node[NumCpn].begin(), Node[NumCpn].end());
	}
}

void loadData()
{
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, a[u].push_back(v);

	for (int u = 1; u <= n; u++)
		if (!Num[u]) Tarjan(u);
}

int Solve()
{
	loadData();

	cout << NumCpn << '\n';
	for (int i = 1; i <= NumCpn; i++, cout << '\n')
		for (int v : Node[i])
			cout << v << " ";

	return 0;
}

int main() { Solve(); }