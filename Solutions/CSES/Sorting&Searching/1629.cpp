// https://cses.fi/problemset/task/1629
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
 
typedef long long ll;
 
pair <int, int> a[N];
int n, res = 0, tmp = 0;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i].se >> a[i].fi;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        if (a[i].se >= tmp)
            tmp = a[i].fi, res++;
    cout << res;
    return 0;
}
