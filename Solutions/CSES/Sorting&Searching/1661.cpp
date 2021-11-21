// https://cses.fi/problemset/task/1661
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
int n, k;
map <long long, long long> f;
long long res = 0, sum = 0;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("I.txt", "r", stdin);
    cin >> n >> k; 
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        f[sum]++;
        sum += x;
        res += f[sum - k];
    }
    cout << res;
    return 0;
}
