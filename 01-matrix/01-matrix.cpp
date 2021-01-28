class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int r, int c)
    {
        if(r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || matrix[r][c] == -1)
            return 10000;
        
        if(matrix[r][c] == 0 || matrix[r][c] == 1)
            return matrix[r][c];
        
        int temp = matrix[r][c];
        
        matrix[r][c] = -1;
        
        int left = 1+dfs(matrix, r, c-1);
        int right = 1+dfs(matrix, r, c+1);
        int down = 1+dfs(matrix, r-1, c);
        int up = 1+dfs(matrix, r+1, c);
        
        matrix[r][c] = min({temp, left, right, down, up});
        return matrix[r][c];
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    matrix[i][j] = 10000;
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    dfs(matrix, i, j);
        return matrix;
        
    }
};