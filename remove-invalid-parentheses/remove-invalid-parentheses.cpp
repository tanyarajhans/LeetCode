class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int cntL = 0, cntR = 0;
        
        for (const char& c: s) {           
            if (c == '(') cntL++; 
            if (c == ')') {
                if (cntL > 0) cntL--;
                else cntR++;
            }
        }
        
        vector<string> res; 
        
        helper(s, 0, cntL, cntR, res);
        
        return res;
    }
     void helper(string s, int start, int cntL, int cntR, vector<string>& res) {
        if (cntL == 0 && cntR == 0) {
            if (isValid(s)) res.push_back(s);
        }
        
        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (s[i] == '(' && cntL > 0) {
                string ss = s.substr(0, i) + s.substr(i + 1);
                helper(ss, i, cntL - 1, cntR, res);
            }
            if (s[i] == ')' && cntR > 0) {
                string ss = s.substr(0, i) + s.substr(i + 1);
                helper(ss, i, cntL, cntR - 1, res);
            }
        }
    }
    
    bool isValid(string s) {
        int count = 0;
        
        for (const char& c: s) {
            if (c == '(') count++;
            if (c == ')') {
                if (count == 0) return false;
                else count--;
            }
        }
        
        return count == 0;
    }
};