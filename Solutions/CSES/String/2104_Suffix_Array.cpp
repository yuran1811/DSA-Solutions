#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 5;
 
ll suf[N], pos[N], tmp[N];
ll L, R, mask, f[N][21];
string s, t;
int n, q;
 
bool Cmp(ll x, ll y)
{
	if (pos[x] != pos[y]) return pos[x] < pos[y];
	x += mask, y += mask;
	return (x < n && y < n) ? pos[x] < pos[y] : x > y;
}
 
void Build()
{
	for (int i = 0; i < n; i++)
		suf[i] = i, pos[i] = s[i];
 
	for (mask = 1;; mask <<= 1)
	{
		sort(suf, suf + n, Cmp);
		for (int i = 0; i < n - 1; i++)
			tmp[i + 1] = tmp[i] + Cmp(suf[i], suf[i + 1]);
		for (int i = 0; i < n; i++) pos[suf[i]] = tmp[i];
		if (tmp[n - 1] == n - 1) break;
	}
}
 
int Check(ll mid, string &t)
{
	int m = t.size(), j = suf[mid];
	int ok = (n - j >= m) ? 0 : -1;
	for (int i = 0; i < min(n - j, m); i++)
	{
		if (s[j + i] < t[i]) return -1;
		if (s[j + i] > t[i]) return 1;
	}
	return ok;
}
 
ll LeftLimit(string &t, ll l, ll r, ll res = -1)
{
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		int v = Check(mid, t);
		if (!v) res = mid, r = mid - 1; else
		if (v < 0) l = mid + 1;
		else r = mid - 1;
	}
	return res;
}
 
ll RightLimit(string &t, ll l, ll r, ll res = -1)
{
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		int v = Check(mid, t);
		if (!v) res = mid, l = mid + 1; else
		if (v < 0) l = mid + 1;
		else r = mid - 1;
	}
	return res;
}
 
void RMQ()
{
	for (int i = 0; i < n; i++) f[i][0] = suf[i];
	for (int j = 1; j <= 20; j++)
		for (int i = 0; i + (1 << j) <= n; i++) 
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
 
ll Query(int l, int r)
{
	int k = log2(r - l + 1);
	return min(f[l][k], f[r - (1 << k) + 1][k]) + 1;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> q; n = s.size(); Build(); RMQ();
	while (q--)
		cin >> t, L = LeftLimit(t, 0, n - 1),
		R = RightLimit(t, L, n - 1),
		cout << (L == -1 ? L : Query(L, R)) << '\n';
	return 0;
}
