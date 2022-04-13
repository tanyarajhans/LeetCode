class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,1));
        int r1=0,r2=n-1,c1=0,c2=n-1;
        int loops=n/2;
        if(n%2){
            loops++;
        }
        if(n==1)
            return ans;
        int r=0,c=0;
        int v=1;
        for(int i=0;i<loops;i++){
            for(;c<=c2;c++){
                ans[r][c]=v;
                v++;
            }
            r++;
            c--;
            for(;r<=r2;r++){
                ans[r][c]=v;
                v++;
            }
            r--;
            c--;
            for(;c>=i;c--){
                ans[r][c]=v;
                v++;
            }
            c++;
            r--;
            for(;r>i;r--){
                ans[r][c]=v;
                v++;
            }
            r++;
            c++;
            c2--;
            r2--;
        }
        return ans;
    }
};