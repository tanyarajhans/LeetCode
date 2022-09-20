class Solution {
public:

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int t[n+1][m+1];
        memset(t,0,sizeof(t));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    t[i][j]=t[i-1][j-1]+1;
                    ans=max(ans, t[i][j]);
                }
                else
                    t[i][j]=0;
            }
        }
        return ans;
    }
};