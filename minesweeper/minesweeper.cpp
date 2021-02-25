class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={0,-1,1,-1,1,-1,0,1};
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        return x>=0 && x<board.size() && y>=0 && y<board[0].size();
    }
    
    void solve(vector<vector<char>>& board, int x, int y){
        if(!isValid(board,x,y))
            return;
        if(board[x][y]=='E'){
            int c=0;
            for(int i=0;i<8;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(isValid(board,xx,yy) && board[xx][yy]=='M'){
                    c++;
                }
            }
            if(c>0)
                board[x][y]='0'+c;
            else{
                board[x][y]='B';
                for(int i=0;i<8;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                solve(board,xx,yy);
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M'){
                board[click[0]][click[1]]='X';
                return board;
        }
        solve(board, click[0], click[1]);
        return board;
    }
};