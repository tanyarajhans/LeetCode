class Solution {
public:
    int mod=1e9+7;
    vector<int> t;
    int solve(int i){
        if(i<=1)
            return 1;
        
        if(i==2)
            return 2;
        
        if(t[i]!=-1)
            return t[i];
        
        int ans=0;
        ans=((2*solve(i-1))%mod+(solve(i-3))%mod)%mod;
        
        return t[i]=ans;
    }
    
    int numTilings(int N) {
        t.resize(N+1,-1);
        return solve(N);
    }
};
