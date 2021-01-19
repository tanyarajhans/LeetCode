class Solution {
public:
    
    
   void backtrack(vector<vector<int>> &t,vector<int> &ans, vector<int>& nums){
       if(ans.size()==nums.size())
           t.push_back(ans);
       
      for(int i=0;i<nums.size();i++){
           if(find(ans.begin(),ans.end(),nums[i]) == ans.end()){
               ans.push_back(nums[i]);
               backtrack(t, ans, nums);
               ans.pop_back();
           }
       }
       
   }
    
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> t;
       vector<int> ans;
       backtrack(t, ans, nums);
       return t;
    }
};
