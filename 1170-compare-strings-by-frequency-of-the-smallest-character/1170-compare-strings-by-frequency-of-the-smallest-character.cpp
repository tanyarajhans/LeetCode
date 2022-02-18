class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size();
        int m=words.size();
        vector<int> v;
        for(int i=0;i<m;i++){
            string s=words[i];
            vector<int> m(26,0);
            for(auto &x:s){
                m[x-'a']++;
            }
            for(int i=0;i<26;i++){
                if(m[i]>0){
                    v.push_back(m[i]);
                    break;
                }
            }
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            string s=queries[i];
            vector<int> m1(26,0);
            int g=-1;
            for(auto &x:s){
                m1[x-'a']++;
            }
            for(int i=0;i<26;i++){
                if(m1[i]>0){
                    g=m1[i];
                    break;
                }
            }
            auto ind=upper_bound(v.begin(), v.end(), g);
            if(ind==v.end())
                ans.push_back(0);
            else{
                int ind1=ind-v.begin();
                ans.push_back(m-ind1);
            }
        }
        return ans;
    }
};