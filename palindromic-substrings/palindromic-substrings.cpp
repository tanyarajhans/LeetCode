class Solution {
public:
    
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        if(n<=0)
            return 0;
        int t[n][n];
        memset(t,0,sizeof(t));
        for(int i=0;i<n;i++){
            t[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
              t[i][i+1]=1;
        }
            
        for(int i=2;i<n;i++){
           for(int j=0;j<n-i;j++){
               if(t[j+1][i+j-1]==1 && s[j]==s[i+j])
                   t[j][i+j]=1;
           }
        }
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                   if(t[i][j])
                       ans++;
           }
        }
        return ans;
    }
};