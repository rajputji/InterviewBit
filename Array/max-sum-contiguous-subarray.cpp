int Solution::maxSubArray(const vector<int> &A)
{
    //using kadane's algorithm
    int maxSoFar=A[0];
    int currMax=A[0];
    for(int i=1;i<A.size();i++)
    {
        currMax=max(A[i],currMax+A[i]);
        maxSoFar=max(maxSoFar,currMax);
    }
    return maxSoFar;
}
