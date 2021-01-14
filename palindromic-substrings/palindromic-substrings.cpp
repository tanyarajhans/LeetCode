class Solution {
public:
     int pal(string &s, int lo, int hi) {
        int res=0;
        while (lo>=0 && hi<s.size()) {
            if (s[lo] != s[hi])
                break;
​
            --lo;
            ++hi;
            res++;
        }
​
        return res;
    }
​
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=pal(s,i,i);
            ans+=pal(s,i,i+1);
        }
        return ans;
    }
};
