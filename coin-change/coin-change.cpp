class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int s=amount;
        
        int t[s+1];
        for(int i=1;i<=s;i++)
            t[i]=INT_MAX-1;
        
        t[0]=0;
        
        for(int i=1;i<=s;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i && t[i-coins[j]]!=INT_MAX-1)
                    t[i]=min(t[i],t[i-coins[j]] +1);
            }
        }
       return t[s]>s? -1: t[s];
    }
};