class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> fc(128, 0); // frequncy counter
        for(auto x : t){
            fc[x]++;
        }
        
        int tsize = t.size(); //overall counter
        int begin = 0, end = 0;
        string ans;
        int minl = INT_MAX; // minimum length of the substring of s that contains t.
        
        while(end < s.size()){
            char endchar = s[end];
            fc[endchar]--;
            if(fc[endchar] >= 0) // Important detail of the this algo.
                tsize--;
            
            end++;
            
            while(tsize == 0){
                int curlen = end - begin;
                if(curlen < minl) {
                    minl = curlen;
                    ans = s.substr(begin, minl);
                }
                
                
                char beginchar = s[begin];
                fc[beginchar]++;
                if(fc[beginchar] > 0)  // Another important detail of the this algo.
                    tsize++;
                begin++;
            }
        }
        
        return ans;
    }
};