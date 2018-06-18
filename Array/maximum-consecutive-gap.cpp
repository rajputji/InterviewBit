int getMaxfromV(vector<int> &val)
{
        int m = INT_MIN;
        for (int i=0; i<val.size(); i++)
        {
            m = max(m, val[i]);
        }
        return m;
}
     
void count_sort(vector<int> &val, int nd)
{
        int n = val.size();
        vector<int> res(n,0);
        vector<int> cnt(10,0);
     
        for (int i = 0; i < n; i++)
        {
            cnt[ (val[i]/nd)%10 ]++;
        }
     
        for (int i = 1; i < 10; i++)
        {
            cnt[i] += cnt[i - 1];
        }
     
        for (int i = n - 1; i >= 0; i--)
        {
            res[ cnt[(val[i]/nd)%10] - 1] = val[i];
            cnt[ (val[i]/nd)%10 ]--;
        }
     
        for (int i = 0; i < n; i++)
        {
            val[i] = res[i];
        }
}
     
void radix_sort(vector<int> &val)
{
         int maxnum = getMaxfromV(val);
         for (int i = 1; maxnum/i > 0; i *= 10)
         {
             count_sort(val, i);
         }
}
     
     
     
     
int Solution::maximumGap(const vector<int> &A)
{
        if(A.size()<2)
            return 0;
        vector<int> val=A;
        radix_sort(val);
        int res = abs(val[1] - val[0]);
        for (int i=2; i<val.size(); i++)
        {
            if (val[i]-val[i-1] > res)
            {
                res = abs(val[i] - val[i-1]);
            }
        }
        return res;
}