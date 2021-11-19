// https://cses.fi/problemset/task/1091
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
typedef long long ll;
 
int n, m;
set <pair <int, int>> f;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) cin >> x, f.insert({-x, i});
    for (int i = 1, x; i <= m; i++) 
    {
        cin >> x;
        auto pos = f.lower_bound({-x, -1});
        if (pos == f.end()) cout << "-1\n";
        else cout << -pos->first << '\n', f.erase(pos);
    }
 
    return 0;
}
