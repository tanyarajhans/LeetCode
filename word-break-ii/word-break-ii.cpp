class Solution {
public:
    vector<string> ans;
    int n;
    
    void backtrack(string s, int i, vector<string>& dict, string curr) {
        if(i==n){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        
        for(int p=i;p<n;p++){
            string t=s.substr(i, p-i+1);
            if(find(dict.begin(), dict.end(), t)!=dict.end()){
                backtrack(s,p+1, dict, curr+t+" ");
            }
        }
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        string curr="";
        backtrack(s, 0, wordDict, curr);
        return ans;
    }
};