class Solution {
public:
    int t[501][501];
    
    int solve(string word1, string word2, int i, int j){
        if(i==0 && j==0)
            return 0;
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(t[i][j]!=-1)
            return t[i][j];
        if(word1[i-1]==word2[j-1])
            return t[i][j]=solve(word1,word2,i-1,j-1);
        int x=min(min(solve(word1,word2,i-1,j),solve(word1,word2,i,j-1)),solve(word1,word2,i-1,j-1))+1;
        return t[i][j]=x;
    }
    
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        memset(t,-1,sizeof(t));
        return solve(word1, word2, n, m);
    }
};