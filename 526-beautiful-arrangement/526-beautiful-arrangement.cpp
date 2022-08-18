class Solution {
public:
    int ans=0;
    int used[16];
    
    void solve(int ind, vector<int>&v, int n){
        if(ind>n){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!used[i] && (ind%i==0 || i%ind==0)){
                used[i]=1;
                solve(ind+1,v,n);
                used[i]=0;
            }
        }
        
    }
    
    int countArrangement(int n) {
        vector<int> v;
        memset(used,0,sizeof(used));
        solve(1,v,n);
        return ans;
    }
};