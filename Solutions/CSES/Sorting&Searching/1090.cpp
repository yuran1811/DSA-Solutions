// https://cses.fi/problemset/task/1090
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
typedef long long ll;
 
int n, m, res = 0, a[N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater <int>());
    int i = 1, j = n;
    while (i <= j)
    {
        if (a[i] + a[j] <= m) res++, i++, j--;
        else i++, res++;
    }
    cout << res;
    return 0;
}
