class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
       if(n==0)
            return 0;
       int profit[k + 1][n + 1];
       memset(profit,0,sizeof(profit)); 
       for (int i = 1; i <= k; i++) { 
        int prev = INT_MIN; 
        for (int j = 1; j < n; j++) { 
            prev = max(prev,profit[i - 1][j - 1] - prices[j - 1]); 
            profit[i][j] = max(profit[i][j - 1],prices[j] + prev); 
        } 
    } 
  
    return profit[k][n - 1];
    }
};
