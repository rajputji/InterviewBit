vector<vector<int> > Solution::generate(int A) {
    if(A==0)
        return {};
    vector<vector<int>> res(A);
    
    res[0].push_back(1); //0th row [1]
    
    //from 1 to (A-1)th row
    for(int i = 1; i < A; i++)
    {
        res[i].push_back(1); //first element in each row is 1
        for(int j = 1; j < i; j++)
        {
            //simply A[c]=A[c]+A[c-1] from previous row
            res[i].push_back(res[i-1][j] + res[i-1][j-1]);
        }
        res[i].push_back(1); // last element in each row is also 1
    }
    return res;
}
