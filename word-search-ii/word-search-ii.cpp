class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    bool solve(vector<vector<char>> board, int i, int j, int n, int m, string s, int ind){
        if(ind==s.size())
            return true;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && board[x][y]==s[ind]){
                board[x][y]='_';
                if(solve(board,x,y,n,m,s,ind+1))
                    return true;
                board[i][j]=s[ind];
            }
        }
        return false;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n=board.size();
        int m=board[0].size();
        for(auto x: words){
            bool f=true;
            for(int i=0;i<n && f==true;i++){
                for(int j=0;j<m && f==true;j++){
                    if(board[i][j]==x[0]){
                        board[i][j]='_';
                        if(solve(board,i,j,n,m,x,1)){
                            ans.push_back(x);
                            f=false;
                        }
                        board[i][j]=x[0];
                    }
                }
            }
        }
        return ans;
    }
};