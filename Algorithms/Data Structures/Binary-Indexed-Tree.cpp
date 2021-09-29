struct BIT
{
	vector <int> bit;
	void Init(int n) {bit.resize(n + 5, 0);}
	void Up(int i, int val) {for (; i <= n; i += -i & i) bit[i] += val;}
	int Get(int i, int res = 0)
	{
		for (; i > 0; i -= -i & i)
			res += bit[i];
		return res;
	}
};
