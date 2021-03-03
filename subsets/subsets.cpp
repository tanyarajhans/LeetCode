class Solution {
public:
    
    void backtrack(int p, vector<int> &v, vector<int>& nums, vector<vector<int>> &ans){
       ans.push_back(v);
       for(int i=p;i<nums.size();i++){
            v.push_back(nums[i]);
            backtrack(i+1,v,nums,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> curr;
       backtrack(0,curr,nums,ans);
       return ans;
    }
};