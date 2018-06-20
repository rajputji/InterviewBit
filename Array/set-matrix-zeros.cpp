void Solution::setZeroes(vector<vector<int> > &A) {
    bool row[A.size()];
    bool col[A[0].size()];
    for(int x=0;x<A.size();x++)
        row[x]=0;
    for(int x=0;x<A[0].size();x++)
        col[x]=0;    
    
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (A[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    
    for (int i = 0; i <A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if ( row[i] == 1 || col[j] == 1 )
            {
                A[i][j] = 0;
            }
        }
    }
}
