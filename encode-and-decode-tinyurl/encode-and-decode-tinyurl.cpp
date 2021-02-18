class Solution {
public:
    string s="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id = 0;
    map<string, string> url;
    
    string solve(int n){
        string ans;
        if(n<62){
            return s.substr(0, s[n]);
        }
        while(n>0){
            ans+=s[n%62];
            n=n/62;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s=solve(id);
        id++;
        url[s]=longUrl;
        return "http://tinyurl.com/" + s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int ind=shortUrl.size()-1;
        while(shortUrl[ind]!='/')
            ind--;
        string s=shortUrl.substr(ind+1);
        return url[s];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));