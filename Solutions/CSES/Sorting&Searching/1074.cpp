// https://cses.fi/problemset/task/1074
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
long long res = 0, sum = 0, a[N];
int n;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    sum = a[n / 2 + (n & 1)];
    for (int i = 1; i <= n; i++)
        res += abs(sum - a[i]);
    cout << res;
    return 0;
}
