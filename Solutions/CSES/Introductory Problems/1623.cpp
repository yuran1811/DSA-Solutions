// https://cses.fi/problemset/task/1623
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
 
typedef long long ll;
 
ll ABS(ll a) {return a > 0 ? a : -a;}
 
int main() 
{
    ll s = 0, res;
    int a[N], n;
    
    cin >> n;
    for (int i = 0; i < n; i++) 
    	cin >> a[i], s += a[i];
 
    res = s;
    for (int b = 0; b < 1 << (n - 1); b++) 
    {
        ll tmp = 0;
        for (int i = 0; i < n - 1; i++)
            if (b & 1 << i)
                tmp += a[i];
            
        tmp = ABS(tmp - (s - tmp));
        res = min(res, tmp);
    }
    cout << res;
    return 0;
}
