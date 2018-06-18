vector<int> Solution::getRow(int A) {
    vector<int> res;
    A++;// k is 0 based. k = 0, corresponds to the row [1] 
    
    int C = 1;// used to represent C(line, i)
    for (int i = 1; i <= A; i++)  
    {
        res.push_back(C); // The first value in a line is always 1
        C = C * (A - i) / i;
    }
    return res;
}