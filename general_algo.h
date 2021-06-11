class general {
	void enumerateSubset(int i) {
		for (int j = i; j; j = (j - 1) & i) {
			//process j;
			//j is a subset of i;
		}
	}

	
	int bitcount(unsigned int x) {
		x = ((x & 0xaaaaaaaa) >> 1) + (x & 0x55555555);
		x = ((x & 0xcccccccc) >> 2) + (x & 0x33333333);
		x = ((x & 0xf0f0f0f0) >> 4) + (x & 0x0f0f0f0f);
		x = x + (x >> 8);
		x = x + (x >> 16);
		return x & 63;
	}
	

	int quickmul(int x, int y, int MOD) {
		int ret = 1, mul = x;
		while (y) {
			if (y & 1) {
				ret = (long long)ret * mul % MOD;
			}
			mul = (long long)mul * mul % MOD;
			y >>= 1;
		}
		return ret;
	}


};

class disjoint_set {
public:
	vector<int> father;
	vector<int> rank;

	disjoint_set(int _n) :father(_n, 0), rank(_n, 0) {
		for (int i = 0; i < _n; i++) father[i] = i;
	}

	int find(int x) {
		return father[x] == x ? x : (father[x] = find(father[x]));
	}

	void merge(int a, int b) {
		int x = find(a), y = find(b);
		if (x == y) return;
		if (rank[x] <= rank[y]) {
			father[x] = y;
		}
		else father[y] = x;
		if (rank[x] == rank[y]) rank[y]++;
	}
};

class BIT {
public:
	vector<int> tree;

	BIT(int _n) :sum(_n + 1, 0) {
		;
	}

	inline int lowbit(int x) {
		return x & (-x);
	}

	void update(int i, int delta) {
		i++;
		for (int pos = i; pos <= _n; pos += lowbit(pos)) {
			tree[pos] += delta;
		}
	}

	int query(int a) {
		a++;
		int ret = 0;
		for (; a; a -= lowbit(a)) {
			ret += tree[a];
		}
		return ret;
	}

	int query(int a, int b) {
		return query(b) - query(a - 1);
	}
};