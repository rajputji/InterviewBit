vector<int> Solution::flip(string A)
{
    vector<int> V(A.size()); //it will contain if zero then 1, if one then -1.
    vector<int> res;

    for(int i = 0; i<A.size(); i++)
    {
        if(A[i]=='0')   V[i] = 1;
        else            V[i] = -1;
    }

    int sum=0;
    int L=0, R=0;
    int max_sum=INT_MIN;
    int left_ans=0, right_ans=0;

    //now finding maxSum using Kadane's Algorithm
    for(int i=0;i<V.size();i++)
    {
        sum+=V[i];
        if(sum<0)
        {
            L=i+1;
            sum=0;
        }
        else if(sum>max_sum)
        {
            left_ans = L;
            right_ans = i;
            max_sum=sum;
        }
    }

    if(max_sum<=0) //if no improvement can be done
        return res;
    else        //return Left and Right
    {
        res.push_back(left_ans+1);
        res.push_back(right_ans+1);
        return res;
    }
}
