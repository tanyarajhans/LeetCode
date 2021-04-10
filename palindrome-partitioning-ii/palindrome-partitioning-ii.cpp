class Solution {
public:
    int t[2002][2002];
    
    bool isPalindrome(string &s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s, int i, int j){
        if(t[i][j]!=-1)
            return t[i][j];
        if(i>=j)
            return 0;
        if(isPalindrome(s,i,j))
            return t[i][j]=0;
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=0;
            if(isPalindrome(s,i,k)){
                temp=solve(s,k+1,j)+1;
            }
            else{
                t[i][j]=0;
                continue;
            }
            ans=min(ans,temp);
        }
        return t[i][j]=ans;
    }
    
    
    int minCut(string s) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        return solve(s,0,n-1);
    }
};