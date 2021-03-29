class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2)
            return n;
        int t[n+1];
        t[0]=1;
        t[1]=1;
        t[2]=2;
        for(int i=3;i<=n;i++)
            t[i]=t[i-1]+t[i-2];
        return t[n];
    }
};