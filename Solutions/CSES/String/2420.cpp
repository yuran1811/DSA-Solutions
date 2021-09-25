#include <bits/stdc++.h>
using namespace std;
const long long BASE = 311, MOD = 1e9 + 7, N = 2e5 + 5;
 
typedef long long ll;
 
ll Power[4 * N], Inv[4 * N];
string s, t;
int n, m;
 
ll Pow(ll a, ll b) 
{
	if (!b) return 1;
	if (b == 1) return a;
	ll tmp = Pow(a, b >> 1);
	tmp = tmp * tmp % MOD;
	if (b % 2) tmp = tmp * a % MOD;
	return tmp;
}
 
void Prepare()
{
	Power[0] = 1;
	for (int i = 1; i <= n; i++)
		Power[i] = Power[i - 1] * BASE % MOD;
 
	Inv[n] = Pow(Power[n], MOD - 2);
	for (int i = n - 1; i >= 0; i--)
		Inv[i] = Inv[i + 1] * BASE % MOD;
}
 
struct SegTree
{
	int n;
	string s;
	vector <ll> t;
 
	void Init(string x)
	{
		s = " " + x;
		n = x.size();
		t.resize(n * 4 + 1);
	}
 
	void Build(int l, int r, int i) 
	{
		if (l == r) return (void) (t[i] = Power[l] * (s[l] - 'a' + 1) % MOD);
		int m = (l + r) >> 1;
		Build(l, m, i << 1);
		Build(m + 1, r, i << 1 | 1);
		t[i] = (t[i << 1] + t[i << 1 | 1]) % MOD;
	}
 
	int get(int i, int l, int r, int u, int v)
	{
		if (r < u || v < l) return 0;
		if (u <= l && r <= v) return t[i];
		int m = (l + r) >> 1;
		return (get(i << 1, l, m, u, v) + get(i << 1 | 1, m + 1, r, u, v)) % MOD;
	}
 
	void up(int i, int l, int r, int p, char x)
	{
		if (r < p || p < l) return;
		if (l == r) return (void) (t[i] = Power[p] * (x - 'a' + 1) % MOD);
		int m = (l + r) >> 1;
		up(i << 1, l, m, p, x);
		up(i << 1 | 1, m + 1, r, p, x);
		t[i] = (t[i << 1] + t[i << 1 | 1]) % MOD;
	}
 
	int GET(int u, int v) 
	{
		int tmp = get(1, 1, n, u, v);
		tmp = Inv[u] * tmp % MOD;
		return tmp;
	}
 
	void UP(int p, int x) {up(1, 1, n, p, x);}
} S, T;
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s; t = s; reverse(t.begin(), t.end());
	Prepare();
	S.Init(s); S.Build(1, n, 1);
	T.Init(t); T.Build(1, n, 1);
	
	for (int i = 1, c, u; i <= m; i++) 
	{
		cin >> c >> u;
		if (c == 1) 
		{
			char x; cin >> x;
			S.UP(u, x);
			T.UP(n - u + 1, x);
		} else 
		{
			int v; cin >> v;
			cout << (S.GET(u, v) == T.GET(n - v + 1, n - u + 1) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}
