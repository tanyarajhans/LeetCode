class Solution {
public:
    int p[100005];
    
    int find(int x){
        if(p[x]==x)
            return x;
        return p[x]=find(p[x]);
    }
    
    void unionf(int x, int y){
        p[find(x)]=find(y);
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(int i=0;i<n;i++)
            p[i]=i;
        for (int i = 0; i<queries.size(); i++) {
            queries[i].push_back(i);
        }
        auto by_weight = [](auto &a, auto &b) {
            return a[2] < b[2];
        };
        
        sort(queries.begin(), queries.end(), by_weight);
        sort(edges.begin(), edges.end(), by_weight);
        
        vector<bool> ans(queries.size());
        int j = 0;
        for (auto &q : queries) {
            for (; j < edges.size() && edges[j][2] < q[2]; j++) {
                unionf(edges[j][0], edges[j][1]);
            }
            ans[q[3]] = find(q[0])==find(q[1]);
        }
        
        return ans;
    }
};