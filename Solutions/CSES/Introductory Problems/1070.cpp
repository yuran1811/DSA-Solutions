// https://cses.fi/problemset/task/1070
#include <bits/stdc++.h>
using namespace std;
 
int n, a = 1, b = 2;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    if (n == 1) {cout << 1; return 0;} else 
    if (n == 2 || n == 3) {cout << "NO SOLUTION"; return 0;} else
    if (n == 4) {cout << "2 4 1 3"; return 0;}
 
    for (int i = 1; i <= n; i++)
    {
        if (a <= n) cout << a << " ", a += 2; else
        cout << b << " ", b += 2;
    }
    return 0;
}
