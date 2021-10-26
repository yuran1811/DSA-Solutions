// https://cses.fi/problemset/task/1644
#include <iostream>
#include <deque>
#define sz(s) (int (s.size()))
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 5;
const ll oo = 1e18 + 5LL;
 
ll res = -oo, s[N];
int n, l, r;
 
bool mxm(ll &a, ll b) {return a < b ? a = b, 1 : 0;}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		cin >> s[i], s[i] += s[i - 1];
}
 
int Solve()
{
	Load_Data();
	deque <int> q;
	for (int i = l; i <= n; i++)
	{
		while (sz(q) && q.front() < i - r) q.pop_front();
		while (sz(q) && s[i - l] < s[q.back()]) q.pop_back();
		q.push_back(i - l); mxm(res, s[i] - s[q.front()]);
	}
	cout << res;
	return 0;
}
 
int main() {Solve();}
