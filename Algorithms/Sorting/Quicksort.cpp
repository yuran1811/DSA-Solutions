#include <iostream>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

void SORT(int l, int r)
{
	int i = l, j = r;
	int x = a[(l + r) / 2];
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	if (l < j) SORT(l, j);
	if (i < r) SORT(i, r);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	SORT(1, n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}
