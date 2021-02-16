class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> m;
        int n=groupSizes.size();
        for(int i=0;i<n;i++){
            m[groupSizes[i]].push_back(i);
            if(m[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back(m[groupSizes[i]]);
                m[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};