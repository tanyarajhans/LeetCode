class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq (26, 0);
        for (char c : s){
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans=0;
        int maxl=s.size();
        for(int i=0;i<26 && freq[i]>0;i++) {
            if(freq[i]>=maxl){
                ans+=freq[i]-maxl;
                freq[i]=maxl;
            }
            maxl=max(0, freq[i]-1);
        }
        return ans;
    }
};