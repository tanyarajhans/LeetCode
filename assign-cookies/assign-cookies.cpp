class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=min(g.size(),s.size());
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,ans=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};