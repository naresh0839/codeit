// it finds the maximum and minimum 
// contiguous subarray sum for a given array b

double b[];
double calMin() {
    double globalMin = 0, localMin = 0;
    for (int i = 0; i < n; i++) {
        globalMin = min(globalMin, localMin);
        localMin += b[i];
        localMin = min(localMin, 0.);
    }
    return min(globalMin, localMin);
}
double calMax() {
    double globalMax = 0, localMax = 0;
    for (int i = 0; i < n; i++) {
        globalMax = max(globalMax, localMax);
        localMax += b[i];
        localMax = max(localMax, 0.);
    }
    return max(globalMax, localMax);
}