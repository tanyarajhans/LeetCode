class Solution {
public:
    set<vector<string>> s;
    int m;
    
    bool isValid(int r, int c, vector<string> &temp){
        for(int i=0;i<=c;i++){ //check for all colns above it for same row
            if(temp[r][i]=='1')
                return false;
        }
        for(int i=0;i<=r;i++){ //check for all colns above it for same row
            if(temp[i][c]=='1')
                return false;
        }
        for(int i=r,j=c;i<m && j>=0;i++,j--){ //left lower diagonal
            if(temp[i][j]=='1')
                return false;
        }
        for(int i=r,j=c;i>=0 && j>=0;i--,j--){ //left upper diagonal
            if(temp[i][j]=='1')
                return false;
        }
        return true;
    }
    
    void solve(int ind, vector<string> &temp){ //ind is cols
        if(ind==m){
            s.insert(temp);
            return;
        }
        for(int i=0;i<m;i++){ //i is rows
            if(isValid(i, ind, temp)){
                temp[i][ind]='1';
                solve(ind+1, temp);
                temp[i][ind]='0';
            }
        }
        
    }
    
    int totalNQueens(int n) {
        m=n;
        vector<string> temp(n, string(n,'0'));
        int ind=0;
        solve(ind, temp);
        return s.size();
    }
};