class Solution {
public:
    
    int n,m;
    int vis[7][7];
    
    bool solve(int i, int j, int pos, vector<vector<char>>& board, string word){
        if(pos==word.size())
            return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[pos] || vis[i][j]==1){
            return false;
        }
        vis[i][j]=1;
        int d=solve(i+1,j,pos+1,board,word);
        int r=solve(i,j+1,pos+1,board,word);
        int u=solve(i-1,j,pos+1,board,word);
        int l=solve(i,j-1,pos+1,board,word);
        vis[i][j]=0;
        return l|r|u|d;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        bool ans=false;
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    int pos=0;
                    ans|=solve(i,j,pos,board,word);
                }
            }
        }
        return ans;
    }
};