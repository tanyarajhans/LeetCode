class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n==0 && m==0)
            return true;
        int j=0;
        for(int i=0;i<m;i++){
            if(s[j]==t[i]){
                j++;
            }
            if(j==n)
                return true;
        }
        return false;
    }
};