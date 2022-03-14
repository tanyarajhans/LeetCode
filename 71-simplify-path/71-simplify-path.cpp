class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        int n=path.size();
        vector<string> dirs;
        string curr="";
        for (int i = 0; i<n; ++i) {
            char c = path[i];
            if (c == '/') {
                if (!curr.empty()) {
                    if (curr== "..") {
                        if (!dirs.empty()) 
                            dirs.pop_back();
                    } 
                    else if(curr!="."){
                        dirs.push_back(curr);
                    }
                    curr="";
                }
            } 
            else{
                curr+= c;
            }
        }
        if (!curr.empty()) {
            dirs.push_back(curr);
        }
        string ans;
        for (string& s : dirs) {
            ans += "/" + s;
        }
        return ans.empty() ? "/" : ans;
    }
};