// Power Function

int power(int x, int a) {
    if (a == 0) return 1;
    int half = power(x, a / 2);
    half *= half;
    if (a & 1) half *= x;
    return half;
}

// (x ^ a) % p function

int xap(int x, int a, int p) {
    if (a == 0) return 1;
    int half = xap(x, a / 2, p);
    half = (half * half) % p;
    if (a & 1) half = (half * x) % p;
    return half;
}

// Seive Function

int sp[MAXN + 1];
bool vis[MAXN + 1];
void Seive() {
    rep(i, 1, MAXN) sp[i] = i;
    for (int i = 4; i <= MAXN; i += 2) sp[i] = 2, vis[i] = true;
    for (int i = 3; i * i <= MAX; i += 2) {
        if (vis[i]) continue;
        sp[i] = i;
        for (int j = i * i; j <= MAX; j += i) {
            if (vis[j]) continue;
            sp[j] = i;
            vis[j] = true;
        }
    }
}

// Seive for Prime Check

bool isPrime[MAXN];
void checkp() {
    isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) isPrime[i] = true;
    for (int i = 2; i * i <= MAXN; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAXN; j += i) {
            isPrime[j] = false;
        }
    }
}

// Information related to XOR

https :  //codeforces.com/contest/276/problem/D

         Editorial :: :

    A XOR of two numbers has the value of the i -
    th bit set to 1 if and only if their values on this bit differ(i.e.one is zero and the other is one).We can be certain that we can pick two numbers with differing bits on the i - th position and conform to the rest of our solution,
    if the difference between R and L is greater than or equal to 2 ^ i(because the zeroth bit changes state every 2 ^ 0 values, the first one every 2 ^ 1 values and so on).When this difference is lesser than 2 ^ i, we use another key observation : within one of those blocks of length 2 ^ i, the sequences of values where the i - th bit is zero and where it is one are contiguous;
i.e.we just have to check whether the i - th bit of R differs from the i - th bit of L, and then we know whether or not they're in the same subsequence with respect to that bit. If they are not, we can add 2^i to our solution. We carry on until 2^i is lesser than or equal to R.

                                                                                                                    // Tarjan' Algorithm - For Strongly Connected Components in graph

                                                                                                                    https :  //codeforces.com/contest/427/submission/78430146

                                                                                                                             // Modulo of a string with a
                                                                                                                             int
                                                                                                                             mod(string num, int a) {
    int res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
    return res;
}
