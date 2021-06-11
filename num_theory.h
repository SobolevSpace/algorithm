class num_theroy {
public:
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

    int inv(int x, int MOD) {
        return quickmul(x, MOD - 2, MOD);
    }

    void EraSieve(int MAXN) {
        bool isP[MAXN];
        for (int i = 0; i < MAXN; i++) isP[i] = true;
        isP[0] = isP[1] = false;
        for (int i = 2; i < MAXN; i++) {
            if (isP[i]) {
                for (int j = i * i; j < MAXN; j += i) isP[j] = false;
            }
        }
    }

    void EulerSieve(int MAXN) {
        bool isP[MAXN];
        vector<int> primes;
        for (int i = 0; i < MAXN; i++) isP[i] = true;
        isP[0] = isP[1] = false;

        for (int i = 2; i < MAXN; i++) {
            if (isP[i]) {
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p * i >= MAXN) break;
                isP[p * i] = false;
                //the min factor of p*i is p;
                if (i % p == 0) break;
            }
        }
    }
};