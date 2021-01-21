class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1)
            return {-1};
        vector<int> v(n);
        map<int,int> m;
         for(int i=0;i<n;i++)
            m[intervals[i][0]]=i;
             
        for(int i=0;i<n;i++){
            auto it=m.lower_bound(intervals[i][1]);
            if(it==m.end())
                v[i]=-1;
            else
                v[i]=(it->second);
        }
        return v;
    }
};
