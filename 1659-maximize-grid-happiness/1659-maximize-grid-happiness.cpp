class Solution {
public:
    int dp[5][7][7][1<<5][1<<5]; //dp[row][in][ex][inmask][exmask]
    
// Number of introvert people (x)
// Number of extrovert people (y)
// Position of introvert people in the bottom row (mask1)
// Position of extrovert people in the bottom row (mask2)
// Now, you are placing introvert people in current row at maskx and extrovert people at masky, now check for adjacency among them and among people placed below it and update score accordingly.
    
    int solve(int idx, int x, int y, int mask1, int mask2, int m, int n) {
        if(idx<0)
            return 0;
        if(dp[idx][x][y][mask1][mask2]!=-1)
            return dp[idx][x][y][mask1][mask2];
        int ans = INT_MIN, mask;
        for(int maskx=0; maskx<(1<<n); maskx++) { //placing introverts
            for(int masky=0; masky<(1<<n); masky++) { //placing extroverts
                if(maskx&masky)
                    continue;
                int p = __builtin_popcount(maskx);
                int q = __builtin_popcount(masky);
                if(p>x or q>y)
                    continue;
                int cur = 120*p+40*q;
                mask = maskx|masky;
                int m = mask1|mask2;
                for(int i=0; i<n; i++) {
                    int l = ((mask&(mask>>1))>>i)&1; //no of ppl on left
                    int r = ((mask&(mask<<1))>>i)&1; //no of ppl on right
                    if((maskx>>i)&1) { //if current cell is introvert
                        cur = cur-l*30-r*30;
                        if((m>>i)&1)
                            cur -= 30;
                    }
                    if((masky>>i)&1) { //if current cell is extrovert
                        cur = cur+l*20+r*20;
                        if((m>>i)&1)
                            cur += 20;
                    }
                    if(((mask1>>i)&1) and ((mask>>i)&1))
                        cur -= 30;
                    if(((mask2>>i)&1) and ((mask>>i)&1))
                        cur += 20;
                }
                ans = max(ans, cur+solve(idx-1, x-p, y-q, maskx, masky, m, n));
            }
        }
        return dp[idx][x][y][mask1][mask2] = ans;
    }
    
    int getMaxGridHappiness(int m, int n, int in, int ex) {
        int inc=0,exc=0;
        memset(dp,-1,sizeof(dp));
        return solve(m-1, in, ex, 0, 0, m, n);
    }
};