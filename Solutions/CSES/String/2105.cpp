#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 5;
 
ll suf[N], pos[N], tmp[N];
ll lcp[N], mask, n;
string s;
 
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
 
void Process()
{
	for (int i = 0, k = 0; i < n; i++)
		if (pos[i] != n - 1)
		{
			ll j = suf[pos[i] + 1];
			while (s[i + k] == s[j + k]) k++;
			lcp[pos[i]] = k;
			if (k) k--;
		}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; n = s.size(); Build(); Process();
	ll sum = accumulate(lcp, lcp + n, 0LL);
	cout << n * (n + 1) / 2 - sum;
	return 0;
}
