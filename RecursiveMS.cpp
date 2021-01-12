#include <iostream>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
void merge(int a[], int b[], int start, int mid, int end) {
    int ptrl = start, ptrr = mid + 1, cur = start;
    while (ptrl <= mid and ptrr <= end) {
        if (a[ptrl] <= a[ptrr]) {
            b[cur++] = a[ptrl];
            ptrl++;
        } else {
            b[cur++] = a[ptrr];
            ptrr++;
        }
    }
    while (ptrl <= mid) b[cur++] = a[ptrl++];
    while (ptrr <= end) b[cur++] = a[ptrr++];
    for (int i = start; i <= end; i++) {
        a[i] = b[i];
    }
}
void merge_sort(int a[], int b[], int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge_sort(a, b, start, mid);
    merge_sort(a, b, mid + 1, end);
    merge(a, b, start, mid, end);
}   
signed main() {
    boostIO;
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, b, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
// XD