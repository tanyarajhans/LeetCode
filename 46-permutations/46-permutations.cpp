class Solution {
public:
    int n;
    vector<vector<int>> ans;
    
    void solve(int pos, vector<int> &temp, vector<int> &nums){
        if(pos==n){
            ans.push_back(temp);
            return;
        }
       // temp.push_back(nums[pos]);
        for(int i=0;i<n;i++){
            if(find(temp.begin(), temp.end(), nums[i])!=temp.end())
                continue;
            temp.push_back(nums[i]);
            solve(pos+1, temp, nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        int pos=0;
        solve(pos, temp, nums);
        return ans;
    }
};