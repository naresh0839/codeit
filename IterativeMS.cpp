#include <iostream>
using namespace std;
void merge(int a[], int b[], int start, int mid, int end) {
    int ptrl = start, ptrr = mid + 1, cur = start;
    while (ptrl <= mid and ptrr <= end) {
        if (a[ptrl] <= a[ptrr]) {
            b[cur++] = a[ptrl++];
        } else {
            b[cur++] = a[ptrr++];
        }
    }
    while (ptrl <= mid) b[cur++] = a[ptrl++];
    while (ptrr <= end) b[cur++] = a[ptrr++];
    for (int i = start; i <= end; i++) {
        a[i] = b[i];
    }
}
signed main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int sz = 1; sz < n; sz *= 2) {
        for (int start = 0; start < n; start += 2 * sz) {
            int mid = min(start + sz - 1, n - 1);
            int end = min(start + 2 * sz - 1, n - 1);
            merge(a, b, start, mid, end); 
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
// XD