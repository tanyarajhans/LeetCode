class Solution {
public:
    
    void backtrack(vector<int> &t, vector<vector<int>> &ans, int st, int n, int k){
        if(t.size()==k)
        {
            ans.push_back(t);
            return;
        }
        
        for(int i=st;i<n;i++){
            t.push_back(i+1);
            backtrack(t,ans,i+1,n,k);
            t.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(n<k)
            return ans;
        vector<int> t;
        backtrack(t,ans,0,n,k);
        return ans;
    }
};