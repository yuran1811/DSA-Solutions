// https://cses.fi/problemset/task/1619
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
typedef long long ll;
 
int n, res = 0, a[N], b[N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n);
    
    int i = 1, j = 1, tmp = 0;
    while (i <= n)
    {
        if (a[i] < b[j]) tmp++, i++;
        else tmp--, j++;
        res = max(res, tmp);
    }
    cout << res;
    return 0;
}
