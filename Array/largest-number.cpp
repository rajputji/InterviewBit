int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);
 
    // then append X at the end of Y
    string YX = Y.append(X);
 
    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}

string Solution::largestNumber(const vector<int> &A) {

    vector<string> a;
    char s[30];
    int f=0;
    for(int i=0;i<A.size();i++)
    {
       sprintf(s,"%d",A[i]);
       a.push_back(s);
       if(a[i]!="0")
            f=1;
    }
    sort(a.begin(), a.end(), myCompare);
    
    string res;
    
    if(f==0)
            res="0";
    else
    {
        for(auto const &s : a)
        { 
            res += s;
        }
    }
    return res;
}