/**
	Application
	* Finding a substring in a string
	* Finding longest repeating substring
	* Number of distinct substrings
	* Number of distinct substrings length i
	* Longest common prefix of two substrings
	* Longest common substring of two substrings
*/

#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 5;
 
ll suf[N], pos[N], tmp[N], PREFFIX[N];
ll lcp[N], gap, n, m;

string s, t, Combine;
 
bool Cmp(ll x, ll y)
{
	if (pos[x] != pos[y]) return pos[x] < pos[y];
	x += gap, y += gap;
	return (x < n && y < n) ? pos[x] < pos[y] : x > y;
}
 
void Build(const string &s)
{
	for (int i = 0; i < n; i++)
		suf[i] = i, pos[i] = s[i] == '$' ? 0 : s[i];
 
	for (gap = 1;; gap <<= 1)
	{
		sort(suf, suf + n, Cmp);

		for (int i = 0; i < n - 1; i++)
			tmp[i + 1] = tmp[i] + Cmp(suf[i], suf[i + 1]);

		for (int i = 0; i < n; i++) pos[suf[i]] = tmp[i];

		if (tmp[n - 1] == n - 1) break;
	}
}

// Application

void Repeat_Substring()
{
	int Max = max_element(lcp, lcp + n) - lcp;

	if (!lcp[Max])
		return void (cout << "-1\n");

	cout << s.substr(suf[Max], lcp[Max]) << '\n';
}

void Num_Distinct_Substr_Lth_i()
{
	int Prev = 0;
	for (int i = 0; i < n; i++)
		PREFFIX[n - suf[i] + 1]--,
		PREFFIX[Prev + 1]++,
		Prev = lcp[i];

	for (int i = 1; i <= n; i++)
		cout << PREFFIX[i] << " ", PREFFIX[i + 1] += PREFFIX[i];

	cout << '\n';
}

void Num_Distinct_Substr()
{
	ll sum = accumulate(lcp, lcp + n, 0LL);
	cout << n * (n + 1) / 2 - sum;
}
 
void LCP_Build(const string &s)
{
	for (int i = 0, k = 0; i < n; i++)
	{
		if (k) k--;
		ll j = suf[pos[i] - 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
		lcp[pos[i]] = k;
	}
}

void GetLCS()
{
	cin >> s >> t; m = s.size();
	Combine = s + "$" + t + "#";
	n = Combine.size();

	Build(Combine);
	LCP_Build(Combine);

	ll LCS_lth = 0, id;
	vector <ll> f(n);
	for (int i = 0; i < n; i++)
		f[i] = suf[i] >= m ? 2 : 1;

	for (int i = 1; i < n; i++)
		if (f[i] != f[i - 1] && LCS_lth < lcp[i])
			LCS_lth = lcp[i], id = suf[i];

	for (int i = id; i < id + LCS_lth; i++)
		cout << Combine[i];
}

// End

int main()
{
	// GetLCS();
	// cin >> s; n = s.size(); Build(s); LCP_Build(s);
	// Repeat_Substring();
	// Num_Distinct_Substr();
	// Num_Distinct_Substr_Lth_i();
	return 0;
}