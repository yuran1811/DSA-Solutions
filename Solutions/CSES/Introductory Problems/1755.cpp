// https://cses.fi/problemset/task/1755
#include <bits/stdc++.h>
using namespace std;
 
string s, ans, mid;
map <char, int> f;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s; for (char c : s) f[c]++;
    for (auto x : f) 
    {
        ans += string(x.second / 2, x.first);
        if (x.second % 2) mid += x.first;
    }
 
    if (mid.size() > 1) cout << "NO SOLUTION"; else 
    {
        cout << ans + mid;
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}
