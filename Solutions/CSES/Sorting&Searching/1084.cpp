// https://cses.fi/problemset/task/1084
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
typedef long long ll;
 
int n, m, k, a[N], b[N];
 
bool ok(int l, int r, int x)
{
    return (l <= x && x <= r);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
 
    int i = 1, j = 1, res = 0;
    while (i <= n && j <= m)
    {
        if (ok(a[i] - k, a[i] + k, b[j]) || a[i] == b[j]) res++, i++, j++; else
        if (a[i] > b[j]) j++;
        else i++;
    }
 
    cout << res;
    return 0;
}
