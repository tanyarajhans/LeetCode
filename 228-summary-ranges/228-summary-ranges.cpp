class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return {};
        vector<string> ans;
        int s=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)
                continue;
            if(s==nums[i-1]){
                ans.push_back(to_string(s));
            }
            else{
                ans.push_back(to_string(s)+"->"+to_string(nums[i-1]));
            }
            s=nums[i];
        }
        if(s==nums[n-1]){
            ans.push_back(to_string(s));
        }
        else{
            ans.push_back(to_string(s)+"->"+to_string(nums[n-1]));
        }
        return ans;
    }
};