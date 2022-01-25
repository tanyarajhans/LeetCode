class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=price.size();
        int m=special.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=price[i]*needs[i];
        }
        for(int i=0;i<m;i++){
            bool f=false; //no negative
            for(int j=0;j<n;j++){
                needs[j]-=special[i][j];
            }
            for(int j=0;j<n;j++){
                if(needs[j]<0){
                    f=true;
                    break;
                }
            }
            if(f==false){
                int cost = special[i][n] + shoppingOffers(price, special, needs);
                ans=min(ans, cost);
            }
            for(int j=0;j<n;j++){
                needs[j]+=special[i][j];
            }
        }
        return ans;
    }
    
};