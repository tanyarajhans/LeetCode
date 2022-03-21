class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> m;
        int n=s.size();
        for(int i=0;i<n;i++)
            m[s[i]]=i;
        int st=0,end=m[s[0]];
        for(int i=0;i<n;i++){
            end=max(end, m[s[i]]);
            if(i==end){
                ans.push_back(i-st+1);
                st=i+1;
            }
        }
        return ans;
    }
};