class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> m1;
        vector<int> ans;
        for(int i=0;i<words.size();i++)
            m1[words[i]]++;
        int l=words[0].size();
        int n=l*words.size();
        if(s.size()<n)
            return ans;
        for(int i=0;i<=s.size()-n;i++){
            string t=s.substr(i, n);
            map<string,int> m2;
            int j=0;
            for(;j<t.size();j+=l){
                string v=t.substr(j,l);
                if(m1.find(v)==m1.end())
                    break;
                if(m2[v]==m1[v])
                    break;
                m2[v]++;
            }
            if(j==t.size())
                ans.push_back(i);
        }
        return ans;
    }
};
