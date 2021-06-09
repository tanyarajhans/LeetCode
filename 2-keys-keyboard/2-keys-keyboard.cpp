class Solution {
public:
    int t[1001][1001];
    
    int solve(int n, int st, int val, int copy){
        if(val==n)
            return st;
        if(st>n || val>n)
            return INT_MAX;
        if(t[st][val]!=-1)
            return t[st][val];
        return t[st][val]=min(solve(n, st+1, val+copy, copy), solve(n, st+2,val+val, val));
        
    }
    
    int minSteps(int n) {
        int ans=0;
        memset(t,-1,sizeof(t));
        if(n>1)
        return solve(n, 1, 1,1);
        return ans;
    }
};