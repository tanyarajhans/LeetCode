class Solution {
public:
    int solve(vector<vector<int>>& mat, int x){
        int n=mat.size();
        int r=0, c=n-1;
        int ans=0;
        while(r<n && c>=0){
            if(mat[r][c]<=x){
                ans+=c+1;
                r++;
            }
            else c--;   
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int l=mat[0][0], h=mat[n-1][n-1];
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(solve(mat, mid)>=k){
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};