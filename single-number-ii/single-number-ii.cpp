class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(32);
        for( int k : nums){
            for(int i=0;i<32;i++){
                if(k & (1<<i))
                    v[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(v[i]%3==1){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};
