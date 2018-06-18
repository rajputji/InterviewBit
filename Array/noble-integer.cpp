int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
    {
        int j=i+1;
        while(A[j]==A[i])
            j++;
        int countGreaterInt=A.size()-j;
        if(countGreaterInt==A[i])
            return 1;
    }
    if(A[A.size()-1]==0)
        return 1;
    return -1;
}
