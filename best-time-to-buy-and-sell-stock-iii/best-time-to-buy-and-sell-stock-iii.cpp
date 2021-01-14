class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left[n],right[n];
        int ans=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            ans=max(ans,prices[i]-mini);
            left[i]=ans;
        }
        int maxi=INT_MIN;
        ans=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,prices[i]);
            ans=max(ans,maxi-prices[i]);
            right[i]=ans;
        }
        for(int i=0;i<n;i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};
