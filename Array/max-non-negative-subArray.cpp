vector<int> Solution::maxset(vector<int> &a)
{
    int n=a.size();
    long sum=0,start=0,end=0,tStart=0,tEnd=0,tSum=0,flag=0;
    for(int i=0;i<n;)
    {
         flag=0;
         tStart=i;
         tEnd=i;
         tSum=0;
         while(a[i] >=0 && i<n)
         {
             tEnd=i;
             tSum+=a[i];
             if(a[i]==0)
                flag=1;
             i++;
         }
         if(tSum>sum)
         {
             sum=tSum;
             start=tStart;
             end=tEnd;
         }
         else if(tSum==sum)
         {
             if(tEnd-tStart+1 > start-end+1)
             {
                 start=tStart;
                 end=tEnd;
             }
         }
         while(a[i] < 0 && i<n)
            i++;
    }
        
    vector<int> res;
    int flg=0;
    for(int j=start;j<=end;j++)
    {
        if(a[j] >= 0)
            flg=1;
        res.push_back(a[j]);
    }
    if(flg==0)
        res.clear();
    return res;
}
