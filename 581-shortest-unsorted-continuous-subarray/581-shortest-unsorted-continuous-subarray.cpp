class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        int start=0,end=0;
        for(int i=0;i<v.size();i++) {
            if(nums[i]!=v[i]) {
                start=i;
                break;
            }
        }
        for(int i=v.size()-1;i>=0;i--) {
            if(nums[i]!=v[i]) {
                end=i;
                break;
            }
        }
        if(start!=end) {
            return end-start+1;
        }
        return 0;
    }
};