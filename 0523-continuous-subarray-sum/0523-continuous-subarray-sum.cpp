class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int s=0;
        m[0]=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(m.find(s%k)==m.end()){
                m[s%k]=i+1;
            }
            else if(m[s%k]<i)
                return true;
        }
        return false;
    }
};