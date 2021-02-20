class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        if(k>n)
            return "";
        bool x=true;
        while(x){
            x=false;
            for(int i=1,c=1;i<s.size() && x==false; i++){
                if(s[i]!=s[i-1])
                    c=1;
                else{
                    c++;
                    if(c==k){
                        s=s.substr(0, i-k+1)+s.substr(i+1);
                        x=true;
                    }
                        
                }
            }
        }
        return s;
    }
};