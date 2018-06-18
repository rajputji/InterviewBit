int Solution::solve(vector<string> &A)
{
    //based on answer on 'stack overflow' 
    int n=A.size();
    vector<float> V(n);
    for(int i=0;i<n;i++)
        V[i]=stof(A[i]);
    //X=(0,2/3) , Y=[2/3,1] , Z= (1,2)
    vector<float> rangeX,rangeY,rangeZ;
    for(int i=0;i<n;i++)
    {
        if(V[i]>0.0 && V[i]<(2.0/3.0))
            rangeX.push_back(V[i]);
        else if(V[i]>=(2.0/3.0) && V[i]<=1.0)
            rangeY.push_back(V[i]);
        else if(V[i]>1.0 && V[i]<2.0)
            rangeZ.push_back(V[i]);
    }
    float Xmax1=0.0,Xmax2=0.0,Xmax3=0.0,Xmin1=1.0,Xmin2=1.0;
    for(auto i : rangeX)
    {
        if(i>Xmax1)
            Xmax1=i;
        if(i<Xmin1)
            Xmin1=i;
    }
    for(auto i : rangeX)
    {
        if(i>Xmax2 && i!=Xmax1)
            Xmax2=i;
        if(i<Xmin2 && i!=Xmin1)
            Xmin2=i;
    }
    for(auto i : rangeX)
        if(i>Xmax3 && i!=Xmax1 && i!=Xmax2)
                Xmax3=i;
    float Ymax1=0.0,Ymin1=2.0,Ymin2=2.0;            
    for(auto i : rangeY)
    {
        if(i>Ymax1)
            Ymax1=i;
        if(i<Ymin1)
            Ymin1=i;
    }
    for(auto i : rangeY)
        if(i<Ymin2 && i!=Ymin1)
            Ymin2=i;
    float Zmin1=3.0;
    for(auto i : rangeZ)
        if(i<Zmin1)
            Zmin1=i;

    int X=rangeX.size(),Y=rangeY.size(),Z=rangeZ.size();
    //case 1 : `a \in X, b \in X, C \in X` 
    if(X>=3)
    {
        if(Xmax1+Xmax2+Xmax3 >= 1.0)
        {
            //cout<<"case1"<<" ";
            //cout<<Xmax1+Xmax2+Xmax3<<endl;
            return 1;
        }
    }
    //case 2 :`a \in X, b \in X, C \in Z` 
    if(X>=2 && Z>=1)
    {
        if(Xmin1+Xmin2+Zmin1 <= 2.0)
        {
            //cout<<"case2"<<" ";
            //cout<<Xmin1+Xmin2+Zmin1<<endl;
            return 1;
        }
    }
    //case 3 : `a \in X, b \in Y, C \in Y`
    if(X>=1 && Y>=2)
    {
        if(Xmin1+Ymin1+Ymin2 <= 2.0)
        {
            //cout<<"case3"<<" ";
            //cout<<Xmax1+Ymin1+Ymin2<<endl;
            return 1;
        }
    }
    //case 4 : `a \in X, b \in Y, C \in Z`
    if(X>=1 && Y>=1 && Z>=1)
    {
        if(Xmin1+Ymin1+Zmin1 <= 2.0)
        {
            //cout<<"case4"<<" ";
            //cout<<Xmax1+Ymin1+Zmin1<<endl;
            return 1;
        }
    }
    //case 5 : `a \in X, b \in X, C \in Y` 
    if(X>=2 && Y>=1)
    {
        if( (Xmax1+Xmax2+Ymin1 < 2.0) && (Xmin1+Xmin2+Ymax1 > 1.0) )
        {
            //cout<<"case5"<<" ";
            //cout<<Xmax1+Xmax2+Ymin1<<endl;
            return 1;
        }
    }

    return 0;
}
