class Solution {
public:
    // transpose and then reverse all rows
    
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        // transposing 
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int t=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=t;
            }
        }
        // reversing rows
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int t=mat[i][j];
                mat[i][j]=mat[i][n-j-1];
                mat[i][n-j-1]=t;
            }
        }
    }
};