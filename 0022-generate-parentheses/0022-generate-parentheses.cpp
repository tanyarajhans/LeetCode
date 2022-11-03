class Solution {
public:
    vector<string> ans;
    
    void solve(int o, int c, string t, int n){
        if(t.size()==2*n){
            ans.push_back(t);
            return;
        }
        if(o<n){
            t.push_back('(');
            solve(o+1,c,t,n);
            t.pop_back();
        }
        if(c<o){
            t.push_back(')');
            solve(o,c+1,t,n);
            t.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string t;
        solve(0,0,t,n);
        return ans;
    }
};