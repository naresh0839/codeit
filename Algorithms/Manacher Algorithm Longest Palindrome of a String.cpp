void solve(string &s) {
    int n = s.length();
    int d1[n] = {1}, d2[n] = {0};
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        d1[i] = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
        while (i - d1[i] >= 0 && i + d1[i] < n && s[i - d1[i]] == s[i + d1[i]]) {
            d1[i]++;
        }
        if (i + d1[i] - 1 > r) {
            l = i - (d1[i] - 1);
            r = i + d1[i] - 1;
        }
    }  // as
    l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        d2[i] = (i > r ? 0 : min(r - i + 1, d2[l + r - i + 1]));
        while (i - d2[i] - 1 >= 0 && i + d2[i] < n && s[i - d2[i] - 1] == s[i + d2[i]]) {
            d2[i]++;
        }
        if (i + d2[i] - 1 > r) {
            l = i - d2[i];
            r = i + d2[i] - 1;
        }
    }
    int m = -1, M = -1, even, odd;
    for (int i = 0; i < n; i++) {
        if (d1[i] > m) {
            m = d1[i];
            odd = i;
        }
        if (d2[i] > M) {
            M = d2[i];
            even = i;
        }
    }
    if (2 * (m - 1) + 1 > 2 * M) {
        // print odd length palindromic string
        cout << s.substr(odd - (m - 1), 2 * (m - 1) + 1);
    } else {
        // print even length palindromic string
        cout << s.substr(even - M, 2 * M);
    }
}

// https://cp-algorithms.com/string/manacher.html
