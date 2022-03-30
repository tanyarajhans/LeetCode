class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<int> v;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         v.push_back(matrix[i][j]);
        //     }
        // }
        int l=0, r=n*m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[mid/m][mid%m]<target)
                l=mid+1;
            else if(matrix[mid/m][mid%m]>target)
                r=mid-1;
            else 
                return true;
        }
        return false;
    }
};