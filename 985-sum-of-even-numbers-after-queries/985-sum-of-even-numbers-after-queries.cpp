class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans(m);
        int sum=0;
        for(int i=0;i<n;i++)
            sum+= (nums[i]%2==0 ? nums[i] : 0);
        
        for(int i=0;i<m;i++){
            int val=queries[i][0];
            int idx=queries[i][1];
            if(nums[idx] % 2 ==0)
                sum-=nums[idx];
            nums[idx]= nums[idx] + val;
            if(nums[idx]%2 ==0 )
                sum+=nums[idx];
            ans[i]=sum;
        }
        return ans;
    }
};