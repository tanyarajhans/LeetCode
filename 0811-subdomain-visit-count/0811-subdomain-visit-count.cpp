class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto cd : cpdomains) {
            int i = cd.find(" ");
            int n = stoi(cd.substr (0, i));
            string s ="."+cd.substr (i + 1);
            for (int i = 0; i < s.size(); i++)
                if (s[i] == '.')
                    m[s.substr(i + 1)] += n;
        }
        vector<string> ans;
        for (auto k : m)
            ans.push_back (to_string(k.second) + " " + k.first);
        return ans;
    }
};