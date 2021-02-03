class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> m(A.begin(), A.end());
        vector<int> ans(A.size());
        for(int i=0;i<B.size();i++){
            auto it=m.upper_bound(B[i]);
            if(it==m.end()){
                ans[i]=*(m.begin());
                m.erase(m.begin());
            }
            else{
                ans[i]=*it;
                m.erase(it);
            }
        }
        return ans;
    }
};