class Solution {
public:
   
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        bool t[n+1][m+1];
        memset(t,false,sizeof(t));
        t[0][0]=true;
        for (int j=0;j<m && p[j]=='*'; j++) {
            t[0][j+1]=true;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                 if(p[j-1]=='*'){
                    t[i][j]=(t[i-1][j] || t[i][j-1]);
                }
                else
                t[i][j]=((s[i-1]==p[j-1] || p[j-1]=='?') && t[i-1][j-1]);   
            }
        }
        return t[n][m];
    }
};
