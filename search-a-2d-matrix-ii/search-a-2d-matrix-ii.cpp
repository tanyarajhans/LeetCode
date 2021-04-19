class Solution {
public:
    int n,m;
    bool solve(vector<vector<int>>& mat, int t, int i, int j){
        if(mat[i][j]==t)
            return true;
        bool ans=false;
        if(t>mat[i][j])
        {
            if(i+1<n)
                ans=ans|solve(mat,t,i+1,j);
            
        }
        else{
            if(j-1>=0)
                ans=ans|solve(mat,t,i,j-1);
        }
        return ans;
            
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n=matrix.size();
        m=matrix[0].size();
        return solve(matrix, target, 0, m-1);
    }
};