class Solution {
public:
    void backtrack(vector<vector<int>> &ans,vector<int> &t, int j, int k, int n){
        if(n==0 && t.size()==k){
            ans.push_back(t);
            return;
        }
        
        for(int i=j;i<=9;i++){
                t.push_back(i);
                backtrack(ans,t,i+1,k,n-i);
                t.pop_back();
            }
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        backtrack(ans, t, 1, k,n);
        return ans;
    }
};