class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k)
            return true;
        if(n<k)
            return false;
        int odd=0;
        int a[26]={0};
        for(int i=0;i<n;i++)
            a[s[i]-'a']++;
        for(int i=0;i<26;i++)
            if(a[i]%2!=0)
                odd++;
        return odd<=k && k<=n;
    }
};