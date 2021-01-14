class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int m=S.size(),n=T.size();
        string s1="",s2="";
        int skip=0;
        for(int i=m-1;i>=0;){
            if(S[i]=='#'){
                skip++;
                i--;
            }
            else if(skip>0){
                skip--;
                i--;
            }
            else{
                s1+=S[i];
                i--;
            }
        }
        skip=0;
        for(int i=n-1;i>=0;){
            if(T[i]=='#'){
                skip++;
                i--;
            }
            else if(skip>0){
                skip--;
                i--;
            }
            else{
                s2+=T[i];
                i--;
            }
        }
        return (s1==s2);
    }
};
