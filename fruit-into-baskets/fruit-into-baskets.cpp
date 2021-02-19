class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n=tree.size();
        unordered_map<int, int> m;
        int i=0,j=0;
        for(i=0;i<n;i++){
            m[tree[i]]++;
            if(m.size()>2){
                m[tree[j]]--;
                if(m[tree[j]]==0){
                    m.erase(tree[j]);
                }  
                j++;
            }
        }
        return i-j;
    }
};