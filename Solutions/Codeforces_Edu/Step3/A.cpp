#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

ll suf[N], pos[N], tmp[N], gap;
string s, t;
int n, q;
ll L, R;

bool Cmp(ll x, ll y)
{
	if (pos[x] != pos[y]) return pos[x] < pos[y];
	x += gap; y += gap;
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

int Check(ll mid, const string &t)
{
	int m = t.size(), j = suf[mid];
	int ok = (n - j >= m) ? 0 : -1;
	for (int i = 0; i < min(m, n - j); i++)
	{
		if (s[i + j] < t[i]) return -1;
		if (s[i + j] > t[i]) return 1;
	}
	return ok;
}

int Left(const string &t, ll l, ll r = n - 1, ll res = -1)
{
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		int val = Check(mid, t);
		if (!val) res = mid, r = mid - 1; else
		if (val < 0) l = mid + 1; else
		r = mid - 1;
	}
	return res;
}

int Right(const string &t, ll l, ll r = n - 1, ll res = -1)
{
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		int val = Check(mid, t);
		if (!val) res = mid, l = mid + 1; else
		if (val < 0) l = mid + 1; else
		r = mid - 1;
	}
	return res;
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> q; n = s.size(); Build();
}

int Scorpio()
{
	Load_Data();
	while (q--)
		cin >> t, L = Left(t, 0), R = Right(t, L),
		cout << (L == -1 ? 0 : R - L + 1) << '\n';
	return 0;
}

int main() {Scorpio();}
