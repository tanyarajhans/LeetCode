class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int t[n+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=i;j++){
                t[i]=max(t[i-1], max(t[i],prices[i-1]-prices[j-1]));
                if(j-2>=0)
                   t[i]=max(t[i],t[j-2]+prices[i-1]-prices[j-1]); 
            }
        }
        return t[n];
    }
};
