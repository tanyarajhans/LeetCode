class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int maxi=0;
        int mini=0;
        while(maxi<n-1){
            int curr=0;
            for(int i=mini;i<=maxi;i++){
                curr=max(curr, i+nums[i]);
            }
            mini=maxi+1;
            maxi=curr;
            ans++;
        }
        return ans;
    }
};