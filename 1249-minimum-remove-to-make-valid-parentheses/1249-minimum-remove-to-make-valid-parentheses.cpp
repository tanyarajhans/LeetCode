class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(c==0){
                    s[i]='*';
                }
                else c--;
            }
            else{
                if(s[i]=='(')
                    c++;
            }
        }
        c=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==')'){
                c++;
            }
            else if(s[i]=='('){ 
                if(c==0){
                    s[i]='*';
                }
                else c--;
                
            }
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};