class Solution {
public:
     bool isPalindrome(string s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    void backtrack(vector<vector<string>> &ans, vector<string> &t, int p, string &s){
        if(p==s.size())
            ans.push_back(t);
        for(int i=p;i<s.size();i++){
           if(isPalindrome(s,p,i)){
               t.push_back(s.substr(p,i-p+1));
               backtrack(ans,t,i+1,s);
               t.pop_back();
           }
        }
        
    }
    
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        backtrack(ans,t,0,s);
        return ans;
    }
};