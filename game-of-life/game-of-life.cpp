class Solution {
public:
    int k[3]={0, -1, 1};
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=0;
                for(int ii=max(i-1,0); ii<min(i+2,n); ii++){
                    for(int jj=max(j-1,0); jj<min(j+2,m); jj++){
                        live+=board[ii][jj]&1;
                    }
                }
                live-=board[i][j];
                if((board[i][j]==1 && live==2)|| live==3)
                    board[i][j]|=2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    board[i][j]>>=1;
            }
        }
        
    }
};