class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if (nums[i]>0) 
                break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1,k=n-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];
                if(s==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(k>j && nums[k]==nums[k-1])
                        k--;
                    while(j<k && nums[j]==nums[j+1])
                        j++;
                    k--;
                    j++;
                }
                    
                else if(s>0)
                    k--;
                else j++;
            }
        }
        return ans;
    }
};