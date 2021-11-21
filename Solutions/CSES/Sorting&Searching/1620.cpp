// https://cses.fi/problemset/task/1620
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
int n, k, a[N];
 
bool ok(long long mid)
{
    long long tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp >= k) return true;
        tmp += mid / a[i];
    }
    return tmp >= k;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k; for (int i = 1; i <= n; i++) cin >> a[i];
 
    long long l = 1, r = (long long) 2e18;
    while (l <= r)
    {
        long long m = (l + r) >> 1;
        if (!ok(m)) l = m + 1;
        else r = m - 1;
    }
    cout << l;
    return 0;
}
