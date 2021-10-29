// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long f[N];
int n;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= min(i, 6); j++)
    		(f[i] += f[i - j]) %= MOD;
    cout << f[n];
    return 0;
}
