class Solution {
public:
     void backtrack(vector<vector<int>> &t,vector<int> &ans, vector<int>& nums, vector<bool> &vis){
       if(ans.size()==nums.size())
           t.push_back(ans);
       
      for(int i=0;i<nums.size();i++){
            if(vis[i] || ((i>0 && nums[i]==nums[i-1]) && !vis[i-1]))
               continue;
               vis[i]=true;
               ans.push_back(nums[i]);
               backtrack(t, ans, nums, vis);
               vis[i]=false;
               ans.pop_back();
           
       }
       
   }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      sort(nums.begin(),nums.end());
       vector<vector<int>> t;
       vector<int> ans;
       vector<bool> vis(nums.size());
       backtrack(t, ans, nums, vis);
       return t; 
    }
};
