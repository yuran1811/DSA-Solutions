// https://cses.fi/problemset/task/1686
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5, oo = 1e9 + 7;

vector <int> a[N], SCC;

int Low[N], Num[N], cnt = 0;
int NumCpn, CpnID[N];
int n, m, NumCoin[N];

stack <int> s;

ll mxm(ll &a, ll b) {return a < b ? a = b, 1 : 0;}
int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}

void Tarjan(int u, vector <ll> &f)
{
	s.push(u);
	Low[u] = Num[u] = ++cnt;
	for (int v : a[u])
		if (!Num[v]) 
			Tarjan(v, f), mnz(Low[u], Low[v]);
		else mnz(Low[u], Num[v]);

	if (Low[u] == Num[u])
	{
		CpnID[u] = ++NumCpn;
		do
		{
			int v = s.top(); s.pop();
			CpnID[v] = NumCpn;
			Low[v] = Num[v] = oo;
			SCC.push_back(v);
		} while (SCC.back() != u);

		for (int Vertex : SCC)
			for (int v : a[Vertex])
				mxm(f[NumCpn], f[CpnID[v]]);
		for (int Vertex : SCC)
			f[NumCpn] += NumCoin[Vertex];
		SCC.clear();
	}
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> NumCoin[i];
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, a[u].push_back(v);
}

int Solve()
{
	Load_Data();
	vector <ll> f(n + 1, 0);
	for (int u = 1; u <= n; u++)
		if (!Num[u]) Tarjan(u, f);
	for (ll x : f) mxm(f[n], x);
	cout << f[n];
	return 0;
}

int main() {Solve();}
