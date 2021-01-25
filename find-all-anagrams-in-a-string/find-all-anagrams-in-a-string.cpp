class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()>s.size())
            return ans;
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0;i<p.size();i++)
        {
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        for(int i=p.size();i<s.size();i++)
        {
            if(a==b)
                ans.push_back(i-p.size());
            b[s[i-p.size()]-'a']--;
            b[s[i]-'a']++;
            
        }
        if(a==b)
           ans.push_back(s.size()-p.size());
        return ans;
    }
};
