class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void backtrack(int i, vector<int>& candidates, vector<int> &curr, int target){
        if(target==0)
        {
                ans.push_back(curr);
                return;
        }
        if(i==n)
        {
            return;
        }
        if(target<0)
            return;
        curr.push_back(candidates[i]);
        backtrack(i, candidates, curr, target-candidates[i]);
        curr.pop_back();
        backtrack(i+1, candidates, curr, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        n=candidates.size();
        backtrack(0, candidates, curr, target);
        return ans;
    }
};