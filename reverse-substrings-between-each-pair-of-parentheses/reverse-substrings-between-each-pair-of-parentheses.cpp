class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        int o=0, c=n-1;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
               o=i;
            if(s[i]==')'){
               c=i;
               string ss=s.substr(o+1, c-o-1);
               reverse(ss.begin(), ss.end());
               string t=s.substr(0,o)+ss+s.substr(c+1);
               return reverseParentheses(t);
            }
                
        }
        return s;
    }
};