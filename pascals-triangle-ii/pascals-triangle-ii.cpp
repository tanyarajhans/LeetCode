class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans(n+1, 1);
        for(int i=1;i<=n;i++){
            vector<int> t(i+1, 1);
            for(int j=1;j<i;j++)
                t[j]=ans[j-1]+ans[j];
            ans=t;
        }
        return ans;
    }
};