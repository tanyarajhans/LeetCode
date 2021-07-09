class Solution {
public:
    vector<int> ans;
    
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int r1=0, r2=n-1, c1=0, c2=m-1;
        while(r1<=r2 && c1<=c2){
            for(int c=c1;c<=c2;c++)
                ans.push_back(mat[r1][c]);
            for(int r=r1+1;r<=r2;r++)
                ans.push_back(mat[r][c2]);
            if(r1<r2 && c1<c2){
                for(int c=c2-1;c>c1;c--)
                    ans.push_back(mat[r2][c]);
                for(int r=r2;r>r1;r--)
                    ans.push_back(mat[r][c1]);
            }
            
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};