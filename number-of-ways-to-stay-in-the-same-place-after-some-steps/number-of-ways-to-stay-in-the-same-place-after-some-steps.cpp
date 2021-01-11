class Solution {
public:
    int t[502][502];
    long long int mod =1e9+7;
    
    int solve(int steps, int pointer, int arrLen){
        if(steps<0)
            return 0;
        
        if(steps==0){
            if(pointer==0)
                return 1;
            else
                return 0;
        }
        if(pointer<0 || pointer>=arrLen)
            return 0;
        
        
        if(t[steps][pointer]!=-1)
            return t[steps][pointer];
        
        int l=solve(steps-1, pointer-1, arrLen);
        int r=solve(steps-1, pointer+1, arrLen);
        int s=solve(steps-1, pointer, arrLen);
        
        return t[steps][pointer]=((l+r)%mod+s%mod)%mod;
    }
    
    int numWays(int steps, int arrLen) {
        memset(t,-1,sizeof(t));
        return solve(steps, 0, arrLen);
    }
};
