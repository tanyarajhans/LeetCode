class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int, int> m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<n && sum<x;i++){
            sum+=nums[i];
            m[sum]=i;
        }
        if(m[sum]==n-1){
            if(sum==x)
                return m[sum]+1;
            return -1;
        }
        if(sum==x)
            ans=m[sum]+1;
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            if(m.find(x-sum)!=m.end())
            {
                if(ans!=-1){
                    ans=min(ans, m[x-sum]+1+n-i);
                }
                else
                    ans=min(n, m[x-sum]+1+n-i);
            }
        }
        return ans;
    }
};