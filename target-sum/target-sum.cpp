class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        int sum=0,s=0,z=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]==0)
                z++;
        }
        if(S>sum)
            return 0;
        if((S+sum)%2!=0)
            return 0;
        s=(sum+S)/2;
        int t[n+1][s+1];
        memset(t,0,sizeof(t));
        for(int i=0;i<n+1;i++){
            t[i][0]=1;
        }
        for(int i=0;i<s+1;i++){
            t[0][i]=0;
        }
        t[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s+1;j++){
               if(nums[i-1]==0)
                   t[i][j]=t[i-1][j];
               else if(nums[i-1]<=j)
                   t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return (1<<z)*t[n][s];
    }
};