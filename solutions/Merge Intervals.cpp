/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool sortByStart(Interval a, Interval b) {
        return a.start < b.start;
}

class Solution {
public:
    
    vector<Interval> merge(vector<Interval>& intervals) {
        // sort intervals by start value
        sort(intervals.begin(),intervals.end(),sortByStart);
        int n = intervals.size();
        vector<Interval> merged;
        
        if(n==0)
            return merged;
        
        // add first interval to merged.
        // compare the last interval on merged to second interval and so on.
        merged.push_back(intervals[0]);
        if(n==1)
            return merged;
        
        for(int i=1; i<n; i++)
        {
            //compare last interval on merged to ith interval in intervals
            if(merged.back().end >= intervals[i].start) // overlap?
            {
                merged.back().end = max(merged.back().end, intervals[i].end); // merged 
            }
            else // no overlap
            {
                merged.push_back(Interval(intervals[i].start, intervals[i].end)); // push as is
            }
        }
        return merged;
    }
};
