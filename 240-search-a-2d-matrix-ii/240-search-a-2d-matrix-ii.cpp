class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        int r=0,c=m-1;
        while(r<n && c>=0){
            if(mat[r][c]==target){
                return true;
            }
            else if(mat[r][c]>target){
                c--;
            }
            else
                r++;
        }
        return false;
    }
};