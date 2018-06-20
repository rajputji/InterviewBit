void Solution::rotate(vector<vector<int> > &A) {
    int rows=A.size();
    int cols=A[0].size();
    int temp;
    
    //step 1 : find the tranpose of matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
    // step 2: reverse the Rows of tranpose
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            temp = A[i][j];
            A[i][j] = A[i][cols - 1 - j];
            A[i][cols - 1 - j] = temp;
        }
    }
}
