class Solution {
public:
    
    int t[1003][1003];
    
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        memset(t,0,sizeof(t));
        t[0][0]=0;
        for(int i=1;i<=n;i++)
            t[i][0]=(int)s1[i-1]+t[i-1][0];
        for(int i=1;i<=m;i++)
            t[0][i]=(int)s2[i-1]+t[0][i-1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    t[i][j]=t[i-1][j-1];
                else
                    t[i][j]=min(s1[i-1]+t[i-1][j], s2[j-1]+t[i][j-1]);
            }
        }
        return t[n][m];
    }
};