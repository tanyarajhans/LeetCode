class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int left[n],right[n];
        // int ans=0,mini=INT_MAX;
        // for(int i=0;i<n;i++){
        //     mini=min(mini,prices[i]);
        //     ans=max(ans,prices[i]-mini);
        //     left[i]=ans;
        // }
        // int maxi=INT_MIN;
        // ans=0;
        // for(int i=n-1;i>=0;i--){
        //     maxi=max(maxi,prices[i]);
        //     ans=max(ans,maxi-prices[i]);
        //     right[i]=ans;
        // }
        // for(int i=0;i<n;i++) {
        //     ans = max(ans, left[i] + right[i]);
        // }
        // return ans;
        
        int b1=INT_MAX, b2=INT_MAX;
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            b1=min(b1, prices[i]);
            s1=max(s1, prices[i]-b1);
            b2=min(b2, prices[i]-s1);
            s2=max(s2, prices[i]-b2);
        }
        return s2;
    }
};