class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void backtrack(int ind, vector<int>& nums, vector<int> temp){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        backtrack(ind+1,nums,temp);
        while(ind+1<n && nums[ind]==nums[ind+1]){
            temp.push_back(nums[ind]);
            ind++;
        }
        temp.push_back(nums[ind]);
        backtrack(ind+1, nums, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        int ind=0;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(ind, nums, temp);
        return ans;
    }
};