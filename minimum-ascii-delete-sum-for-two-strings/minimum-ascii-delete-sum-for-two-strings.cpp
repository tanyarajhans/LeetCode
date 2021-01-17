class Solution {
public:
    
    int t[1003][1003];
    
    int minimumDeleteSum(string s1, string s2) {
        memset(t,-1,sizeof(t));
        int n=s1.size(),m=s2.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0){
                    t[i][j]=0;
                }
                else if(i<=0 && j>0){
                t[i][j] = (int)s2[j-1] + t[i][j-1];
                } 
                else if(j<=0 && i>0) {
                t[i][j] = (int)s1[i-1] + t[i-1][j];
                } 
                else {
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = t[i-1][j-1];
                } else {
                    t[i][j] = min(s1[i-1]+t[i-1][j], s2[j-1]+t[i][j-1]);
                }
            }
            }
        }
        return t[n][m];
    }
};
