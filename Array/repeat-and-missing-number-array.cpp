vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    vector<int> res;
    int N=A.size();
    long long sumOfN=(long long)(N*(N+1)/2), arraySum=0;
    long long sumOfNsqr=(long long)(N*(N+1)*(2*N+1)/6), arraySumsqr=0;

    for(int i=0;i<A.size();i++)
    {
        arraySum+=A[i];
        arraySumsqr+=(long long)A[i]*A[i];
    }

    long long BMinusA=sumOfN-arraySum;// sum of 1..N = sum of arr ele
                                     // + missing B - repeated A
    long long BsqrMinusAsqr=sumOfNsqr-arraySumsqr;
                                    // sum of 1^2,2^2...N^2 = sum arr ele^2
                                    // + missing B^2 - repeated A^2
    long long BPlusA=(long long)BsqrMinusAsqr/BMinusA;
                                //(B^2-A^2)=(B+A)(B-A)
    long long b=(long long)(BMinusA+BPlusA)/2;
                                // B-A+B+A=2B/2=B
    long long a=BPlusA-b;   //B+A-B=A

    res.push_back(a);
    res.push_back(b);
    return res;
}
