// https://cses.fi/problemset/task/2431
#include <bits/stdc++.h>
using namespace std;
 
unsigned long long n, m, k, t;
 
int main()
{
    cin >> t;
    while (t--)
    {
        m = k = 1;
        cin >> n;
        while(n > 9 * m * k)
        {
            n -= 9 * m * k;
            m *= 10;
            k++;
        }
        m += (n - 1) / k;
        n = (n - 1) % k + 1;
        cout << to_string(m)[n - 1] << endl;
    }
    return 0;
}
