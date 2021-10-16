// https://cses.fi/problemset/task/1202
#include <iostream>
#include <vector>
#include <queue>
#define fi first
#define se second
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> plli;
 
const int N = 2e6 + 5, MOD = 1e9 + 7;
const ll oo = 1e18 + 5LL;
 
vector <pii> a[N];
int n, m, Cnt = 0;
 
int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}
int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
 
void Dijk(int s, int t)
{
	priority_queue <plli> Q; Q.push({0, s});
	vector <ll> d(n + 5, oo);
	vector <int> o;
 
	while (Q.size())
	{
		int u = Q.top().se;
		ll du = Q.top().fi;
		Q.pop();
		if (d[u] < oo) continue;
		d[u] = -du;
		o.push_back(u);
		for (pii v : a[u])
			Q.push({du - v.se, v.fi});
	}
 
	vector <int> cnt(n + 1), sp(n + 1, n), lp(n + 1);
	cnt[1] = 1; sp[1] = lp[1] = 0;
	for (int u : o)
		for (pii v : a[u])
		{
			if (d[v.fi] != d[u] + v.se) continue;
			cnt[v.fi] += cnt[u];
			if (cnt[v.fi] >= MOD) cnt[v.fi] -= MOD;
			mnz(sp[v.fi], sp[u] + 1);
			mxm(lp[v.fi], lp[u] + 1);
		}
	cout << d[t] << " " << cnt[t] << " " << sp[t] << " " << lp[t] << '\n';
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w,
		a[u].push_back({v, w});
}
 
int Solve()
{
	Load_Data();
	Dijk(1, n);
	return 0;
}
 
int main() {Solve();}
