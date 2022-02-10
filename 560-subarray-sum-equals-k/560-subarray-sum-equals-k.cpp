class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int s=0;
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(m.find(s-k)!=m.end())
                    ans+=m[s-k];
            if(s==k)
                ans++;
            m[s]++;
        }
        return ans;
    }
};