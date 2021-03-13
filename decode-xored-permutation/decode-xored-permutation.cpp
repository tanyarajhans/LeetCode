class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        int x=n+1;
        int tot=0;
        for(int i=1;i<=x;i++)
            tot^=i;
        int p=0;
        for(int i=0;i<n;i++){
            p^=encoded[i];
            tot^=p;
        }
        //Now tot contains the first number;
        vector<int> ans(n+1);
        ans[0]=tot;
        for(int i=0;i<n;i++){
            ans[i+1]=(tot^encoded[i]);
            tot=ans[i+1];
        }
        return ans;
    }
};