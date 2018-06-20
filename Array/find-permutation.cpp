vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int> res;
    int low=1,high=B;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='D')
            res.push_back(high--);
        else
            res.push_back(low++);
    }
    res.push_back(low);
    return res;
}
