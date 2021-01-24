class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int c[26]={0};
        
        int l=0,r=0,maxl=0,maxc=0;
        
        for(r=0;r<n;r++){
            c[s[r]-'A']++;
            int cc=c[s[r]-'A'];
            maxc=max(cc,maxc);
            
            while(r-l-maxc+1>k){
                c[s[l]-'A']--;
                l++;
            }
            
            maxl=max(maxl, r-l+1);
        }
        
        return maxl;
    }
};
