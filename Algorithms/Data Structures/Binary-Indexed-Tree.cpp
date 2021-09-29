struct BIT
{
	vector <int> bit1, bit2;

	void Init(int n)
	{
		bit1.resize(n + 5, 0);
		bit2.resize(n + 5, 0);
	}

	void Up(vector <int> &bit, int i, int val)
	{
		for (; i <= n; i += -i & i)
			bit[i] += val;
	}

	void Range_Up(int l, int r, int val)
	{
		Up(bit1, l, val);
		Up(bit1, r + 1, -val);
		Up(bit2, l, val * (l - 1));
		Up(bit2, r + 1, -val * r);
	}

	int Get(int i, int res = 0)
	{
		for (; i > 0; i -= -i & i)
			res += bit[i];
		return res;
	}

	int Range_Get(int l, int r)
	{
		int SumR = Get(bit1, r) * r - Get(bit2, r);
		int SumL = Get(bit1, l - 1) * (l - 1) - Get(bit2, l - 1);
		return SumR - SumL;
	}
};
