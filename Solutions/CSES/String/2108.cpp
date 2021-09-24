#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
 
typedef long long ll;
 
const int N = 1e6 + 5;
 
ll suf[N], pos[N], tmp[N], lcp[N], gap;
string s;
int n;
 
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
 
void LCP_Build()
{
	for (int i = 0, k = 0; i < n; i++)
		if (pos[i] == n - 1) k = 0; else
		{
			ll j = suf[pos[i] + 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
			lcp[pos[i]] = k;
			if (k) k--;
		}
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; n = s.size(); Build(); LCP_Build();
}
 
int Scorpio()
{
	Load_Data();
	ll k, Prev = 0, Cur = 0;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		if (Cur + n - suf[i] - Prev >= k)
		{
			ll j = Prev;
			string res = s.substr(suf[i], j);
			while (Cur < k)
				res += s[suf[i] + j], Cur++, j++;
			return cout << res, 0;
		}
		Cur += n - suf[i] - Prev;
		Prev = lcp[i];
	}
	return 0;
}
 
int main() {Scorpio();}
