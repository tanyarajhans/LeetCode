class Solution {
public:
    int fact[10];
    string ans;
    vector<int> index;
    
    int fac(int x){
        int p=1;
        for(int i=2;i<=x;i++){
            p*=i;
        }
        return p;
    }
    
    void solve(int n, int k){
        if(n==1){
            ans+=to_string(index.back());
            return;
        }
        int ind=(k/fact[n-1]);
        if(k%fact[n-1]==0)
            ind--;
        ans+=to_string(index[ind]);
        index.erase(index.begin()+ind);
        k-=fact[n-1]*ind;
        solve(n-1,k);
    }
    
    string getPermutation(int n, int k) {
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=9;i++){
            fact[i]=fac(i);
        }
        for(int i=1;i<=n;i++)
            index.push_back(i);
        solve(n,k);
        return ans;
    }
};