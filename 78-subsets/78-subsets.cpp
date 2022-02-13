class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(int p, int n, vector<int>& nums, vector<int>& curr){
        if(p==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[p]);
        backtrack(p+1, n, nums, curr);
        curr.pop_back();
        backtrack(p+1, n, nums, curr);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr;
        backtrack(0, n, nums, curr);
        return ans;
    }
};