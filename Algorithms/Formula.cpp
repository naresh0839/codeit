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

// ncr mod p function
int ncr(int n, int i) {
    int res = fac[n], div = fac[n - i] * fac[i];
    div %= mod;
    div = xap(div, mod - 2);
    res = (res * div) % mod;
    return res;
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

// Subsequence exists with sum K or not
bool subset[maxn][maxn];
bool isSubsetSum(vector<int> &set, int n, int sum) {
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }
    return subset[n][sum];
}

// Regarding GCD

suppose you have a linear array and a[i] <= 10^12
then number of distinct values of gcd(all subarrays ending on r) is log2(10^12)  

// for finding the next permutation of an array or a string

just find the largest suffix which is decreasing if whole string is decreasing then 
it next permutation is sorted one of itself else just replace a[startSuffix - 1] with
its next bigger in suffix part and reverse the suffix or sort the suffix because it wiil be minimum with the next character replaced

// for finding the last permutation of an array or a string 

just find the largest suffix which is increasing if whole string is increasing then 
it previous permutation is sorted one of itself in descending order else just replace a[startSuffix - 1] with
its first smaller in suffix part and reverse the suffix or sort the suffix decreasingly because it wiil be maximum with the next character replaced


// for finding the nth fibonacci using matrix exponentiation

Method I :: 
Let matrix X = {{1, 1}, {1, 0}} to the nth power matrix be Y
then Y[0][0] will represent Fib(n + 1)

Method II :: 
F(2n) = F(n)[2*F(n+1) – F(n)]
F(2n + 1) = F(n)2 + F(n+1)2


// if a and b are coprime then gcd(a + b, a * b) is 1


/* 
int n;
cin >> n;
int cnt = 0;
for (int i = 0; i < (1 << n); i++) {
    for (int j = i; j; j = (j - 1) & i) {
        cnt++;
    }
}
cout << cnt << endl;
// cnt is almost 387158345 for n = 18
*/ 