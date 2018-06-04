vector<int> Solution::spiralOrder(const vector<vector<int> > &A)
{
    vector<int> res;
    //set the top,bottom,left & right pointers
    int T=0,B=A.size()-1,L=0,R=A[0].size()-1;
    int dir=0;
    while(L<=R && T<=B)
    {
        switch(dir)
        {
            case 0 : for(int k=L;k<=R;k++)
                        res.push_back(A[T][k]);
                     T++;
                     break;
            case 1 : for(int k=T;k<=B;k++)
                        res.push_back(A[k][R]);
                     R--;
                     break;
            case 2 : for(int k=R;k>=L;k--)
                        res.push_back(A[B][k]);
                     B--;
                     break;
            case 3 : for(int k=B;k>=T;k--)
                        res.push_back(A[k][L]);
                     L++;
                     break;
        }
        dir=(dir+1)%4;
    }
    return res;
}
