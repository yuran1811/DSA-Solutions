// https://cses.fi/problemset/task/1684
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 2e5 + 5, oo = 1e9 + 7;

vector <int> a[N];

int Low[N], Num[N], cnt;
int Cpn_ID[N], NumCpn;
int n, m, Get[N];

stack <int> s;

int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}

void Tarjan(int u)
{
	Low[u] = Num[u] = ++cnt;
	s.push(u);

	for (int v : a[u])
		if (!Num[v]) Tarjan(v), mnz(Low[u], Low[v]);
		else mnz(Low[u], Num[v]);

	if (Low[u] == Num[u])
	{
		Cpn_ID[u] = ++NumCpn;
		int v;
		do
		{
			v = s.top(); s.pop();
			Num[v] = Low[v] = oo;
			Cpn_ID[v] = NumCpn;
		} while (v != u);
	}
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= n; i++)
	{
		char x, y;
		cin >> x >> u >> y >> v;
		if (x == '-') u = 2 * m - u + 1;
		if (y == '-') v = 2 * m - v + 1;
		a[u].push_back(2 * m - v + 1);
		a[v].push_back(2 * m - u + 1);
	}
}

int Solve()
{
	Load_Data();
	for (int u = 1; u <= 2 * m + 1; u++)
		if (!Num[u]) Tarjan(u);

	for (int i = 1; i <= m; i++)
		if (Cpn_ID[i] == Cpn_ID[2 * m - i + 1])
			return cout << "IMPOSSIBLE", 0;
		else Get[i] = (Cpn_ID[i] > Cpn_ID[2 * m - i + 1]);

	for (int i = 1; i <= m; i++)
		cout << (Get[i] ? "+" : "-");
	return 0;
}

int main() {Solve();}
