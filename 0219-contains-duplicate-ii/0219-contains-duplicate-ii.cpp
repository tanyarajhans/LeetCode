class Solution {
public:
    map<int,int> m;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=i;
            }
            else{
                if(i-m[nums[i]]<=k)
                    return true;
                m[nums[i]]=i;
            }
        }
        return false;
    }
};