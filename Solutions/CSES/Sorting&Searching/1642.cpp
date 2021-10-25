// https://cses.fi/problemset/task/1642
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1005;
 
int n, k, a[N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k; for (int i = 1; i <= n; i++) cin >> a[i];
    
    map <int, pair <int, int>> mp;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            mp[a[i] + a[j]] = {i, j};
 
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int tmp = k - a[i] - a[j];
            if (tmp && mp.count(tmp) && mp[tmp].fi > j)
            {
                cout << i << " " << j << " " << mp[tmp].fi << " " << mp[tmp].se;
                return 0;
            }
        }
    cout << "IMPOSSIBLE";
    return 0;
}
