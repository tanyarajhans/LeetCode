class Solution {
public:
    
//     bool isValid(int r, int c, char ch, vector<vector<char>>& board){
//         for(int i=0;i<9;i++){
//             if(i!=r && board[i][c]==ch)
//                 return false;
//             if(i!=c && board[r][i]==ch)
//                 return false;
//             if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch){
//                 if(!(3*(r/3)+i/3==r && 3*(c/3)+i%3==c))
//                 return false;
//             }
                
//         }
//         return true;
//     }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        set<int> rows[9];
        set<int> cols[9];
        set<int> blocks[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch=='.')
                    continue;
                int curr=ch-'0';
                if(rows[i].count(curr)>0 || cols[j].count(curr)>0 || blocks[i/3*3+j/3].count(curr)>0)
                    return false;
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[i/3*3+j/3].insert(curr);
            }
        }
        return true;
    }
};