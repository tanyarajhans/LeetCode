class Solution {
public:
    bool vis[201][201];
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx, int p, int n, int m){
        if(i>=n || j>=m || i<0 || j<0 || board[i][j]!=word[idx] || vis[i][j]==true)
        return false;
        
        if(idx+1==p)
            return true;
        
        vis[i][j]=true;
        
        bool ans= dfs(board, word, i+1, j, idx+1, p, n, m) || dfs(board, word, i, j+1, idx+1, p, n, m) || dfs(board, word, i-1, j, idx+1, p, n, m) || dfs(board, word, i, j-1, idx+1, p, n, m);
        vis[i][j]=false;
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0])
                    if(dfs(board, word, i, j, 0, word.size(), n, m))
                        return true;
            }
        }
        return false;
    }
};
