// https://cses.fi/problemset/task/1754
#include <bits/stdc++.h>
#define OK cout << "YES\n"
#define NOK cout << "NO\n"
using namespace std;
 
int t;
long long a, b;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if ((a + b) % 3 == 0)
        {
            if (a < b) swap(a, b);
            if (b * 2 >= a) OK; else NOK;
        } else NOK;
    }
    return 0;
}
