// https://cses.fi/problemset/task/2216
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
const int N = 2e5 + 5;
 
pair <int, int> a[N];
int n, res = 1;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].fi, a[i].se = i;
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++)
        if (a[i].se < a[i - 1].se) res++;
    cout << res;
    
