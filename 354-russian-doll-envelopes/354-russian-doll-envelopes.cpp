class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;
        for(int i=0;i<n;i++){
            int l=0, r=dp.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(envelopes[dp[mid]][1]<envelopes[i][1])
                    l=mid+1;
                else
                    r=mid-1;
            }
            if(l==dp.size())
                dp.push_back(i);
            else
                dp[l]=i;
        }
        return dp.size();
    }
};