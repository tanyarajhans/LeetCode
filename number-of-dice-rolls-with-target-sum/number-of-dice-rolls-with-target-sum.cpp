class Solution {
public:
    int t[32][1001]; //dices and target
    int mod=1e9+7;
    int solve(int d, int f, int target){
        if(d==0){
            if(target==0)
                return 1;
            return 0;
        }
        if(target<0)
                return 0;
        if(d*f<target)
            return 0;
        if(d*f==target)
            return 1;
        if(t[d][target]!=-1)
            return t[d][target];
        long long ans=0;
        for(int i=1;i<=f;i++){
            ans=(ans+solve(d-1, f, target-i))%mod;
        }
        return t[d][target]=ans;
    }
    
    
    int numRollsToTarget(int d, int f, int target) {
        memset(t,-1,sizeof(t));
        return solve(d,f,target);
    }
};