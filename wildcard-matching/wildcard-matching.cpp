class Solution {
public:
    bool match(string& s, string& p, int i, int j, vector<vector<int>>& v){
        if(i==s.size()&&j==p.size())
            return true;
        else if(i==s.size()) 
            return (p[j]=='*'&& match(s,p,i,j+1,v));
        else if(j==p.size())
            return false;
        
        if(v[i][j]!=-1) return v[i][j];
        
        if(p[j]=='*')
            return v[i][j]= (match(s,p,i,j+1,v)||match(s,p,i+1,j,v));
        
        if(p[j]=='?'||s[i]==p[j])
            return v[i][j] = match(s,p,i+1,j+1,v);
        
        return false;
    }
    
    bool isMatch(string s, string p) {
    vector<vector<int>> v(s.size(), vector<int>(p.size(), -1));  
       return match(s,p,0,0,v);
    }
};