class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> m;
        int n=s.size();
        int ans=INT_MAX;
        int i=0,j=0;
        for(auto &x: t)
            m[x]++;
        int c=m.size();
        string res="";
        while(j<n){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0)
                    c--;
                while(c==0){
                    if(j-i+1<ans){
                       ans=min(ans, j-i+1);
                        res=s.substr(i,j-i+1);
                    }
                    if(m.find(s[i])!=m.end()){
                        if(m[s[i]]==0)
                            c++;
                        m[s[i]]++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans==INT_MAX)
            return "";
        return res;
    }
};