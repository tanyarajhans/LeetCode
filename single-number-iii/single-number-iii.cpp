class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long xorr=0;
        for(auto i: nums)
            xorr^=i;
        vector<int> ans(2);
        xorr &= -xorr;
        int p=0,q=0;
        for(auto i: nums){
            if(i&xorr)
                p^=i;
            else
                q^=i;
        }
        ans[0]=p;
        ans[1]=q;
        return ans;
    }
};