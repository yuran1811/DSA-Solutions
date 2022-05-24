#include <iostream>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

void HeapSort(int n, int i)
{
	int root = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[root]) root = l;
	if (r < n && a[r] > a[root]) root = r;

	if (root != i)
	{
		swap(a[i], a[root]);
		HeapSort(n, root);
	}
} 

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = n - 1; i >= 0; i--) HeapSort(n, i);
	for (int i = n - 1; i >= 0; i--)
		swap(a[0], a[i]), HeapSort(i, 0);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}