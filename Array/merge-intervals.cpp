/*
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector<Interval> res;
    int S=-1,E=-1,f=0;
    
    //case 1 : intervals.size()==0 
    if(intervals.size()==0)
    {
        res.push_back(newInterval);
    }
    //case 2 : newInterval being an interval preceding all intervals in the array.
    else if(newInterval.end < intervals[0].start)
    {
        res.push_back(newInterval);
        for(int i=0;i<intervals.size();i++)
            res.push_back(intervals[i]);
    }
    //case 3 : newInterval being an interval succeeding all intervals in the array.
    else if(newInterval.start > intervals[intervals.size()-1].end)
    {
        for(int i=0;i<intervals.size();i++)
            res.push_back(intervals[i]);
        res.push_back(newInterval);
    }
    //case 4: newInterval falling between any two intervals.
    else
    {
        //cout<<"case 4"<<endl;
        for(int i=0;i<intervals.size();i++)
        {
            //cout<<"S = "<<S<<"  E= "<<E<<endl;
            f=0;
            if(newInterval.start>=intervals[i].start  && 
                newInterval.start<=intervals[i].end )
            {
                S=min(newInterval.start,intervals[i].start);
            }
            if(S==-1 && (newInterval.start < intervals[i].start) )
            {
                S=newInterval.start;
            }
            if(newInterval.end>=intervals[i].start && 
                newInterval.end<=intervals[i].end )
            {
                E=max(newInterval.end,intervals[i].end);
                Interval I(S,E);
                res.push_back(I);
                f=1;
            }
            if(E==-1 && S!=-1 && intervals[i].start > newInterval.end)
            {
                E=newInterval.end;
                Interval I(S,E);
                res.push_back(I);
                //res.push_back(intervals[i]);
            }
            if( ((S==-1 && E==-1) || (S!=-1 && E!=-1)) && f==0)
            {
                res.push_back(intervals[i]);
            }
        }
    }
    // case 5 : newInterval covering all given intervals
    if(S!=-1 && E==-1)
    {
        E=newInterval.end;
        Interval I(S,E);
        res.push_back(I);
    }
    return res;
}