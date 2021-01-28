class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l=0, r=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='(')
                l++;
            if(s[i]==')')
                r++;
            if(r>l){
                s[i]='#';
                l=0;
                r=0;
            }      
        }
        l=0;
        r=0;
        for(int i=s.size()-1; i>=0;i--){
            if(s[i]=='(')
                l++;
            if(s[i]==')')
                r++;
            if(l>r){
                s[i]='#';
                l=0;
                r=0;
            }      
        }
        string ans="";
        for(char c: s){
            if(c!='#')
                 ans+=c;
        }
        return ans;
    }
};