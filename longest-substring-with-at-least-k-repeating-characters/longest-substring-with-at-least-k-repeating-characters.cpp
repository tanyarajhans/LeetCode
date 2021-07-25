class Solution {
public:
    
    
//     int solve(string s, int s, int e, int k){
//         if(e<k)
//             return 0;
        
//     }
    
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n==0 || k>n)
            return 0;
        unordered_map<char, int> c;
        if(k<=1)
            return n;
        for(char ch:s)
            c[ch]++;
        int l=0;
        while(l<n && c[s[l]]>=k)
            l++;
        if(l>=n-1)
            return l;
        int ls1=longestSubstring(s.substr(0, l), k);
        while(l<n && c[s[l]]<k)
            l++;
        int ls2;
        if(l<n)
        ls2=longestSubstring(s.substr(l), k);
        else
        ls2=0;
        return max(ls1,ls2);
    }
};