int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
    int maxDiff,i, j;
    int LMin[n],RMax[n];
    LMin[0] = A[0];
    for (i = 1; i < n; i++)
        LMin[i] = min(A[i], LMin[i-1]);
    RMax[n-1] = A[n-1];
    for (j = n-2; j >= 0; j--)
        RMax[j] = max(A[j], RMax[j+1]);
    
    i = 0, j = 0, maxDiff = 0;
    while (j < n && i < n)
    {
        if (LMin[i] <= RMax[j])
        {
            maxDiff = max(maxDiff, j-i);
            j = j+1;
        }
        else
            i = i+1;
    }
    return maxDiff;
}
