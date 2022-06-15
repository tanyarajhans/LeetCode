class Solution {
public:
    vector<vector<int>> ans;
    int n;
    int used[11];
    
    
    void backtrack(int ind, vector<int>& nums, vector<int>& temp){
        ans.push_back(temp); //try generating of every size = 0,1,2,3...
       // backtrack(ind+1, nums, temp);
        for(int i=ind;i<n;i++){
            if(i==ind || nums[i]!=nums[i-1]){ //first element h to daal do uske baad don't add duplicates
                temp.push_back(nums[i]);
                backtrack(i+1,nums,temp); //size+1
                temp.pop_back();
            }
            
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        int ind=0;
        vector<int> temp;
        memset(used, 0, sizeof(used));
        sort(nums.begin(), nums.end());
        backtrack(ind, nums, temp);
        return ans;
    }
};