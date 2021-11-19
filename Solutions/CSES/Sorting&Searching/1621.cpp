// https://cses.fi/problemset/task/1621
#include <bits/stdc++.h>
#define _f(i,ii,iii) for(int i=ii,(_ii)=iii;i<=(_ii);i++)
using namespace std;
int n,x,cnt,d[200005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n; _f(i,1,n) cin >> d[i];
    sort(d+1,d+1+n);
    x=d[1]; cnt=1;
    _f(i,2,n)
        if (x!=d[i])
        {
            cnt++;x=d[i];
        }
    cout << cnt;
    return 0;
}
