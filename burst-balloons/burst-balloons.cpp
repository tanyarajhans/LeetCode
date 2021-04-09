class Solution {
public:
    int t[505][505];
    
    int solve(vector<int>& a, int i, int j){
        if(i>j)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            int t=solve(a,i,k-1) + solve(a,k+1,j) + a[i-1]*a[k]*a[j+1];
            ans=max(ans,t);
        }
        return t[i][j]=ans;
    }
    
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);  
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums, 1, n-2);
    }
};