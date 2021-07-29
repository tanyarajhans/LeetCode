class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> ans;
        ans.push_back(1);
        vector<vector<int>> res;
        res.push_back(ans);
        for(int i=1;i<numRows;i++){
            vector<int> v(res[i-1]);
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){
                temp.push_back(v[j-1]+v[j]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};