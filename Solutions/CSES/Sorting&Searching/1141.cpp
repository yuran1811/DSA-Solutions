// https://cses.fi/problemset/task/1141
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
set <int> f;
int n, a[N];
int res = 0;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
    	while (j < n && !f.count(a[j + 1])) f.insert(a[++j]);
    	res = max(res, j - i + 1);
        f.erase(a[i]);
    }
    cout << res;
    return 0;
}
