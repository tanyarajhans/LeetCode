class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(32);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                  if((1<<j) & nums[i])
                      v[j]++;
              }  
        }
        for(int j=0;j<32;j++){
             if(v[j]%3==1)
                 ans+=(1<<j);
        }
        return ans;
    }
};