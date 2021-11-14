// https://cses.fi/problemset/task/2165
#include<bits/stdc++.h>
using namespace std;
 
void solve(int a, int b, int c, int n) 
{
	if (!n) return;
	solve(a, c, b, n - 1);
	cout << a << ' ' << c << '\n';
	solve(b, a, c, n - 1);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout << (1 << n) - 1 << endl;
    solve(1, 2, 3, n);
    return 0;
}
