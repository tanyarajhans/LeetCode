class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        vector<int> v(32);
        int n=nums.size();
        for(int i=0;i<n;i++){
           for(int j=0;j<32;j++){
               if((1<<j) & nums[i])
                   v[j]++;
           }   
        }
        for(int j=0;j<32;j++){
           if(v[j]>(n/2))
               ans+=(1<<j);
        }
        return ans;
    }
};