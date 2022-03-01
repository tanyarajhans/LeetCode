class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n);
        ans.push_back(0);
        if(n==0)
            return ans;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                ans[i]=ans[i/2];
            }
            else{
                ans[i]=ans[i-1]+1;
            }
        }
        return ans;
    }
};