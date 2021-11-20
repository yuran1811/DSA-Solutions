// https://cses.fi/problemset/task/1640
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
typedef long long ll;
 
int n, m;
pair <int, int> a[N];
 
int bs(int l, int r, int val)
{
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (val == a[m].first) return a[m].second;
        if (val < a[m].first) r = m - 1;
        else l = m + 1;
    }
    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n < 2) {cout << "IMPOSSIBLE"; return 0;}
 
    for (int i = 1, x; i <= n; i++) cin >> x, a[i] = {x, i};
    sort(a + 1, a + 1 + n);
 
    for (int i = 1; i <= n; i++)
    {
        int pos = bs(i + 1, n, m - a[i].first);
        if (pos)
        {
            if (a[i].second > pos) swap(a[i].second, pos);
            cout << a[i].second << " " << pos; return 0;
        }
    }
 
    cout << "IMPOSSIBLE";
    return 0;
}
