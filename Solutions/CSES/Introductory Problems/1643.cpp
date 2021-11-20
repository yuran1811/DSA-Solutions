// https://cses.fi/problemset/task/1643
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
typedef long long ll;
 
ll n, a[N], s[N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
    ll tmp = 0, res = (ll) (-1e18);
    for (int i = 1; i <= n; i++)
    	res = max(res, tmp = (tmp > 0 ? tmp : 0) + a[i]);
    cout << res;
    return 0;
}
