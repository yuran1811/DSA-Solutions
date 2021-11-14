// https://cses.fi/problemset/task/1622
#include <bits/stdc++.h>
#define _f(i,ii,iii) for(int i=ii,(_ii)=iii;i<=(_ii);i++)
using namespace std;
const int N=4*1e4+999;
int cnt=1;
string s,ans[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    sort(s.begin(),s.end());
    while (next_permutation(s.begin(),s.end()))
    {
        cnt++;
        ans[cnt]=s;
    }
    cout << cnt << endl << s;
    _f(i,1,cnt) cout << ans[i] << endl;
}
