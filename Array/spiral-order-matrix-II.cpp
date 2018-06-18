vector<vector<int> > Solution::generateMatrix(int A) {

    vector<vector<int> > res;
    for(int i=0;i<A;i++)
    {
        vector<int> X(A);
        res.push_back(X);
    }
    int T=0,B=A-1,L=0,R=A-1;
    int dir=0;
    int val=1;
    while(L<=R && T<=B)
    {
        switch(dir)
        {
            case 0 : for(int k=L;k<=R;k++)
                        res[T][k]=val++;
                     T++;
                     break;
            case 1 : for(int k=T;k<=B;k++)
                        res[k][R]=val++;
                     R--;
                     break;
            case 2 : for(int k=R;k>=L;k--)
                        res[B][k]=val++;
                     B--;
                     break;
            case 3 : for(int k=B;k>=T;k--)
                        res[k][L]=val++;
                     L++;
                     break;
        }
        dir=(dir+1)%4;
    }

    return res;
}
