class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long x=0;
        for(int i : nums)
            x^=i;
        int k=(x & (x-1))^x;
        vector<int>res;
        int c=0;
        for(int i : nums){
            if(i & k)
                c^=i;
        }
        res.push_back(c);
        res.push_back(c^x);
        return res;
    }
};
