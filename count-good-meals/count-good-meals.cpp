class Solution {
public:
    int countPairs(vector<int>& d) {
        int n=d.size();
        int i=0,j=n-1,ans=0;
        map<int,int> m;
        int mod=1e9+7;
        for(auto &i: d){
                for(int j=0;j<=21;j++){
                    int p=1<<j;
                    if(m.find(p-i)!=m.end())
                        ans=(ans+m[p-i])%mod;
            }
            m[i]++;
        }
        return ans;
    }
};