void Solution::nextPermutation(vector<int> &A) {
    int i;
    int n=A.size();
    
    for(i=n-2;i>=0;i--)
    {
       if(A[i]<A[i+1])
            break;
    }
    if(i>=0)
    {
        int small=A[i+1],index=i+1;
        for(int j=i+2;j<n;j++)
        {
           if(A[j]<small && A[j]>A[i])
           {
               index=j;
               small=A[j];
           }
        }
            
        //swap 
        int t=A[index];
        A[index]=A[i];
        A[i]=t;
        
        sort(A.begin()+i+1,A.end());
      }
      else //If such arrangement is not possible, rearrange as the lowest possible order
      {
           sort(A.begin(),A.end());
      }
}