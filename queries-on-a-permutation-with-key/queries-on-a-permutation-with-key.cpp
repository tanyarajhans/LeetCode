class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n=queries.size();
        vector<int> v;
        vector<int> ans;
        for(int i=1;i<=m;i++)
            v.push_back(i);
        for(int i=0;i<n;i++){
            auto it=find(v.begin(), v.end(), queries[i]);
            ans.push_back(it-v.begin());
            v.erase(it);
            v.insert(v.begin(), queries[i]);
        }
        return ans;
    }
};