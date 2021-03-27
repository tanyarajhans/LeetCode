class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m=a.size();
        int n=b.size();
        int t[m+1][n+1];
        for(int i=0;i<=m;i++)
            t[i][0]=0;
        for(int i=0;i<=n;i++)
            t[0][i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j], t[i][j-1]);
            }
        }
        int i=m,j=n;
        string ans;
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans.push_back(a[i-1]);
                i--;
                j--;
            }
            else if(t[i-1][j]>t[i][j-1]){
                ans.push_back(a[i-1]);
                i--;
            }
            else{
                ans.push_back(b[j-1]);
                j--;
            }   
        }
        while(i>0){
           ans.push_back(a[i-1]);
           i--; 
        }
         while(j>0){
           ans.push_back(b[j-1]);
           j--; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};