class Solution {
public:
    
    bool isValid(int r, int c, char ch, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(i!=r && board[i][c]==ch)
                return false;
            if(i!=c && board[r][i]==ch)
                return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch){
                if(!(3*(r/3)+i/3==r && 3*(c/3)+i%3==c))
                return false;
            }
                
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch=='.')
                    continue;
                if(!isValid(i, j, ch, board))
                    return false;
            }
        }
        return true;
    }
};