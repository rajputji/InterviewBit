int min(int a, int b, int c){return min(min(a, b), c);}

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int i = 0, j = 0 ;
    int ROW=A.size();
    int COL=A[0].size();
    vector<vector<int>> res;
    for (int line=1; line<=(ROW + COL -1); line++)
    {
        vector<int> x;
        int start_col =  max(0, line-ROW);
        int count = min(line, (COL-start_col), ROW);
        for (int j=count-1; j>=0; j--)
            x.push_back(A[min(ROW, line)-j-1][start_col+j]);
        res.push_back(x);
    }
    return res;
}
