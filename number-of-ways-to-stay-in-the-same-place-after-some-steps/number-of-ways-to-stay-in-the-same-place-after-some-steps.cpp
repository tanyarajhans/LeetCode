class Solution {
public:
    int t[502][502];
    int m=1e9+7;
    
    int solve(int ind, int steps, int n){
        if(steps==0){
            if(ind==0)
                return 1;
            else
                return 0;
        }
            
        if(ind<0 || ind>=n)
            return 0;
        if(t[ind][steps]!=-1)
            return t[ind][steps];
        long long int p=solve(ind-1, steps-1, n);
        long long int q=solve(ind+1, steps-1, n);
        long long int r=solve(ind, steps-1, n);
        return t[ind][steps]=(p%m + q%m + r%m)%m;
    }
    
    int numWays(int steps, int arrLen) {
        int ind=0;
        memset(t,-1,sizeof(t));
        return solve(0, steps, arrLen);
    }
};