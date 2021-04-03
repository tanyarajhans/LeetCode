class Solution {
public:
        
void dfs(vector<vector<char>>& board, int i, int j,int rowsize,int colsize)
{
    if(i < 0 || j < 0 || i >= rowsize || j >= colsize || board[i][j] == 'X' || board[i][j] == '1')
    {
        return;
    }
    
    if(board[i][j] == 'O')
    {
        
        board[i][j] = '1';
       
        dfs(board,i+1,j,rowsize,colsize);
        dfs(board,i,j+1,rowsize,colsize);
        dfs(board,i-1,j,rowsize,colsize);
        dfs(board,i,j-1,rowsize,colsize);
          
        
    }
    
}
    
    void solve(vector<vector<char>>& board) {
       int rows = board.size();
    
    if(rows == 0)
        return;
    
    int cols = board[0].size();
    
    if(cols == 0)
        return;
    
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==0 || j==0 || i==rows-1 || j==cols-1)
            {
                if(board[i][j] == 'O')
                {
                    dfs(board,i,j,rows,cols);
                }
            }
        }
    }
    
    
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(board[i][j] == '1')
            {
                board[i][j] = 'O';
            }
            else if(board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
    }
};