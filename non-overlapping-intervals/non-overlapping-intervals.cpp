class Solution {
public:
  
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(), comp);
        int ans=0;
        vector<int> prev=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev[1])
                ans++;
            else
                prev=intervals[i];
        }
        return ans;
    }
};
