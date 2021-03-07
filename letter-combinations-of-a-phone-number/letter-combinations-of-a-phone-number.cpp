class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> m;
    
    
    void backtrack(int p, string s, string d){
        if(s.size()==d.size()){
            ans.push_back(s);
            return;
        }
        for(int i=p;i<d.size();i++){
            char c=d[i];
            for(int j=0;j<m[c].size();j++){
                char ch=m[c][j];
                s.push_back(ch);
                backtrack(i+1, s, d);
                s.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string s="";
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        if(digits.size()==0)
            return ans;
        backtrack(0, s, digits);
        return ans;
    }
};