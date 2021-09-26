#include <algorithm>
#include <iostream>
#define fi first
#define se second
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pll; 
 
const int N = 2e5 + 5;
 
ll suf[N], pos[N], tmp[N], lcp[N];
ll gap, n, k;
string s;
 
bool Cmp(ll x, ll y)
{
	if (pos[x] != pos[y]) return pos[x] < pos[y];
	x += gap, y += gap;
	return (x < n && y < n) ? pos[x] < pos[y] : x > y;
}
 
void Build()
{
	for (int i = 0; i < n; i++)
		suf[i] = i, pos[i] = s[i];
 
	for (gap = 1;; gap <<= 1)
	{
		sort(suf, suf + n, Cmp);
		for (int i = 0; i < n - 1; i++)
			tmp[i + 1] = tmp[i] + Cmp(suf[i], suf[i + 1]);
		for (int i = 0; i < n; i++) pos[suf[i]] = tmp[i];
		if (tmp[n - 1] == n - 1) break;
	}
}
 
void LCP_Build()
{
	for (int i = 0, k = 0; i < n; i++)
	{
		if (pos[i] == n - 1) continue;
		ll j = suf[pos[i] + 1];
		while (s[i + k] == s[j + k]) k++;
		lcp[pos[i]] = k;
		if (k) k--;
	}
}
 
struct SegTree
{
	bool Marked[10 * N];
	pll t[10 * N];
 
	void Push(int i)
	{
		if (!Marked[i]) return;
		Marked[i] = 0;
		t[i << 1] = t[i << 1 | 1] = {t[i].fi >> 1, 0};
		Marked[i << 1] = Marked[i << 1 | 1] = 1;
	}
 
	void Down(int i)
	{
		ll &val = t[i].se;
		t[i << 1].se += val;
		t[i << 1 | 1].se += val;
		val = 0;
	}
 
	void Up(int l, int r, int i, int u, int v, int val)
	{
		if (v < l || r < u) return;
		if (u <= l && r <= v) return void (t[i].se += val);
		Push(i);
		t[i].fi += 1LL * (min(v, r) - max(u, l) + 1) * val;
		int m = (l + r) >> 1;
		Up(l, m, i << 1, u, v, val);
		Up(m + 1, r, i << 1 | 1, u, v, val);
	}
 
	ll Assign(int l, int r, int i, int u, int v, int val)
	{
		if (v < l || r < u) return t[i].fi + 1LL * (r - l + 1) * t[i].se;
		if (u <= l && r <= v)
		{
			t[i] = {(r - l + 1) * val, 0};
			Marked[i] = 1;
			return t[i].fi;
		}
		Push(i);
		Down(i);
		int m = (l + r) / 2;
		t[i].fi = Assign(l, m, i << 1, u, v, val);
		t[i].fi += Assign(m + 1, r, i << 1 | 1, u, v, val);
		return t[i].fi;
	}
 
	ll Get(int l, int r, int i, int u, int v)
	{
		if (v < l || r < u) return 0;
		if (u <= l && r <= v)
			return t[i].fi + 1LL * (r - l + 1) * t[i].se;
		Push(i);
		t[i].fi += 1LL * (r - l + 1) * t[i].se;
		Down(i);
		int m = (l + r) / 2;
		return Get(l, m, i << 1, u, v) + Get(m + 1, r, i << 1 | 1, u, v);
	}
} T;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> k; n = s.size(); Build(); LCP_Build();
 
	k = 1LL * n * (n + 1) / 2 - k + 1;
	ll Max = (1LL << (32 - __builtin_clz(n + 1))) - 1;
	ll cur = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		T.Up(0, Max, 1, 1, n - suf[i], 1);
		ll Prev = (i ? lcp[i - 1] : 0);
		ll l = Prev + 1, r = n - suf[i];
		ll res = -1;
		while (l <= r)
		{
			ll m = l + (r - l) / 2;
			if (cur + T.Get(0, Max, 1, m, n - suf[i]) >= k)
				res = m, l = m + 1;
			else r = m - 1;
		}
		if (res != -1)
			return cout << s.substr(suf[i], res), 0;
		cur += T.Get(0, Max, 1, Prev + 1, n - suf[i]);
		T.Assign(0, Max, 1, Prev + 1, n - suf[i], 0);
	}
	return 0;
}
