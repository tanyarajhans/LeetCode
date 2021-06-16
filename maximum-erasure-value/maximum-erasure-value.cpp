class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0,maxi=0;
        int n=nums.size();
        unordered_set<int> s;
        int i=0,j=0;
        while(j<n){
            while(s.find(nums[j])!=s.end()){
                s.erase(nums[i]);
                maxi-=nums[i];
                i++;
            }
            s.insert(nums[j]);
            maxi+=nums[j];
            ans=max(ans, maxi);
            j++;
        }
        return ans;
    }
};