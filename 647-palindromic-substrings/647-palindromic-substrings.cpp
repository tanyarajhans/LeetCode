class Solution {
public:
    int expand(string s, int i, int j){
        int ans=0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
            ans++;
        }
        return ans;
    }
    
    
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        if(n<=0)
            return 0;
        
        for(int i=0;i<n;i++){
            ans+=expand(s,i,i);
        }
        for(int i=0;i<n-1;i++){
            ans+=expand(s,i,i+1);
        }
        
        return ans;
    }
};