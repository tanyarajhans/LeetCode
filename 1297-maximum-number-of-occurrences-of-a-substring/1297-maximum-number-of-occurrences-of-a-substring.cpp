class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<char,int> m;
        int i=0,j=0;
        int n=s.size();
        map<string, int> ans;
        while(j<n){
            m[s[j]]++;
            while(m.size()>maxLetters || j-i+1>minSize){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
            }
            if(j-i+1>=minSize && j-i+1<=maxSize) 
                ans[s.substr(i,j-i+1)]++;
            j++;
        }
        int count=0;
        for(auto x: ans){
            cout<<x.first<<" ";
            count=max(count, x.second);
        }
        return count;
    }
};