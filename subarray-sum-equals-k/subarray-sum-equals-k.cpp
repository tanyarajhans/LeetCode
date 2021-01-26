class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> m;
        m[0]=1;
        int s=0,ans=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(m.find(s-k)!=m.end())
                ans+=m[s-k];
            m[s]++;
        }
        return ans;
    }
};
