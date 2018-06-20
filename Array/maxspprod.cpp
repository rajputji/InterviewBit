int Solution::maxSpecialProduct(vector<int> &A)
{
    int n=A.size();
    int B[n],C[n];
    stack<pair<long long int ,int> > st;
    pair<long long int ,int > p;
    //for leftSpecial Value
    p=make_pair(10000000000,0);
    st.push(p);
    for(int i=0;i<n;i++)
    {
        while(A[i] >= st.top().first)
            st.pop();
        B[i]=st.top().second;
        p=make_pair(A[i],i);
        st.push(p);
    }
    
    while(!st.empty())
        st.pop();
    //for rightSpecial Value
    p=make_pair(10000000000,0);
    st.push(p);
    for(int i=n-1;i>=0;i--)
    {
        while(A[i] >= st.top().first)
            st.pop();
        C[i]=st.top().second;
        p=make_pair(A[i],i);
        st.push(p);
    }
    //calculatig the final value
    long long int x,y,m=-1;
    for(int i=0;i<n;i++)
    {
        x=B[i];y=C[i];
        m=max(m,x*y);
    }
    return m%1000000007;
}
