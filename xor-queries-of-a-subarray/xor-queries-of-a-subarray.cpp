class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=arr.size();
        int pre[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=arr[i]^pre[i-1];
        }
        for(vector<int> k: queries){
            int l=k[0];
            int r=k[1];
            if(l==0)
                ans.push_back(pre[r]);
            else
                ans.push_back(pre[r]^pre[l-1]);
        }
        return ans;
    }
};
