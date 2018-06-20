/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 
bool myCompare(Interval x,Interval y)
{
     return x.start < y.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    if(A.size()==0)
        return A;
        
    sort(A.begin(),A.end(),myCompare);
    
    stack<Interval> s;
    s.push(A[0]);
    int n=A.size();
    
    for (int i = 1 ; i < n; i++)
    {
        Interval top = s.top();
 
        if (top.end < A[i].start)
            s.push(A[i]);
 
        else if (top.end < A[i].end)
        {
            top.end = A[i].end;
            s.pop();
            s.push(top);
        }
    }
    vector<Interval> res;
    while (!s.empty())
    {
        Interval t = s.top();
        s.pop();
        res.push_back(t);
    }
    reverse(res.begin(),res.end());
    return res;
}