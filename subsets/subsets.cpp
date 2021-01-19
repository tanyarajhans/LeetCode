class Solution {
public:
    
    void backtrack(int p, vector<int> &v, vector<int>& nums, vector<vector<int>> &ans){
        for(int i=p;i<nums.size();i++){
            v.push_back(nums[i]);
            ans.push_back(v);
            backtrack(i+1,v,nums,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans{vector<int>{}};
       vector<int> curr;
       backtrack(0,curr,nums,ans);
       return ans;
    }
};
