// https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>
using namespace std;

const int oo = 1e6 + 6;

int n, x, f[oo], c[1004], p[1004];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 0; i <= n; i++) 
        for (int j = x - c[i] + 1; j >= 0; j--) 
            f[j + c[i]] = max(f[j + c[i]], f[j] + p[i]);
    cout << f[x];
    return 0;
}
