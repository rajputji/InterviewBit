vector<int> Solution::plusOne(vector<int> &A)
{
    vector<int> res;
    int carry=1;
    //remove 0's before most significant digit
    while(*(A.begin())==0 && A.size()>1)
        A.erase(A.begin());

    for(int i=A.size()-1;i>=0;i--)
    {
        res.push_back((A[i]+carry)%10);
        if(A[i]+carry>9)    carry=1;
        else                carry=0;
    }
    if(carry)   res.push_back(1);

    reverse(res.begin(),res.end());
    return res;
}
