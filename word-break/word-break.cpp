class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        if(n==0) 
            return true;
        unordered_set<string> dict;
        for(auto st:wordDict)
            dict.insert(st);
        dp[n]=true;
        for(int i=n-1;i>=0;i--)
        {   string word="";
            for(int j=i;j<n;j++)
            {
                word+=s[j];
                if(dict.find(word)!=dict.end())
                    if(dp[j+1])
                        dp[i]=true;
            }
        }
        return dp[0];
    }
};