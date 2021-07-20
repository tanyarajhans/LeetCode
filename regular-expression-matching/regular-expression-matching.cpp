class Solution {
public:
    
    bool solve(string &s, string &p, int n, int m){
        if(n==0 && m==0)
            return true;
        if(n==0 && m!=0){
            if(p[m-1]=='*')
                return solve(s,p,n,m-2);
            return false;
        }
        if(n!=0 && m==0)
            return false;
        
        if(s[n-1]==p[m-1] || p[m-1]=='.')
            return solve(s,p,n-1,m-1);
        
        else if(p[m-1]=='*'){
            //0 characters match
            if(solve(s,p,n,m-2))
                return true;
            //if previous character matches
            if(s[n-1]==p[m-2] || p[m-2]=='.')
                return solve(s,p,n-1,m);
            return false;
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return solve(s,p,n,m);
    }
};