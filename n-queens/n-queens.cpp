class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string> &s, int r, int c){
        for(int i=r;i>=0;i--)
            if(s[i][c]=='Q')
                return false;
        for(int i=r,j=c;i>=0 && j>=0;i--,j--)
            if(s[i][j]=='Q')
                return false;
        for(int i=r,j=c;i>=0 && j<s.size();i--,j++)
            if(s[i][j]=='Q')
                return false;
        return true;
    }
    void backtrack(vector<string> &s, int r){
        if(r==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(isValid(s,r,i)){
                s[r][i]='Q';
                backtrack(s,r+1);
                s[r][i]='.';
            }
        }
            
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n, string(n,'.'));
        backtrack(s,0);
        return ans;
    }
};
