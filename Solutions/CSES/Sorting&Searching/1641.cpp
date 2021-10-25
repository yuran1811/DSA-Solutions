// https://cses.fi/problemset/task/1641
#include <bits/stdc++.h>
#define val first
#define ps second

using namespace std;
const int N = 2e5 + 5;
 
int n, k;
pair <int, int> a[N];
 
int bs(int l, int r, int val)
{
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (a[m].val == val) return m;
        if (a[m].val < val) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k; for (int i = 1; i <= n; i++) cin >> a[i].val, a[i].ps = i;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n - 2; i++)
        for (int j = i + 1; j < n; j++)
        {
            int pos = bs(j + 1, n, k - a[i].val - a[j].val);
            if (a[i].val + a[j].val + a[pos].val == k && i != j && j != pos && i != pos)
            {
                cout << a[i].ps << " " << a[j].ps << " " << a[pos].ps;
                return 0;
            }
        }
    cout << "IMPOSSIBLE";
    return 0;
}
