class Solution {
public:
    
    void backtrack(int open, int close, string s, vector<string> &ans, int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            backtrack(open+1, close, s, ans, n);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            backtrack(open, close+1, s, ans, n);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> ans;
        backtrack(0,0,s,ans,n);
        return ans;
    }
};