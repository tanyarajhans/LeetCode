class Solution {
public:
    
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        if(n<=0)
            return 0;
        bool t[n][n];
        memset(t,false,sizeof(t));
        
        for(int i=0;i<n;i++){
            t[i][i]=true;
            ans++;
        }
         for(int i=0;i<n-1;i++){
            t[i][i+1]=(s[i]==s[i+1]);
            ans+=t[i][i+1];
        }
            
        for(int i=3;i<=n;i++){
           for(int j=0,k=j+i-1;k<n;j++,k++){
               t[j][k]=t[j+1][k-1] && (s[j]==s[k]);
               ans+=t[j][k];
           }
        }
        return ans;
    }
};
