class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        vector<string> ans;
        for(int i=0;i<w.size();i++){
            map<char,char> m1;
            map<char,char> m2;
            bool f=false;
            for(int j=0;j<w[i].size();j++){
                char a=w[i][j];
                char b=p[j];
                if(m1.find(a)==m1.end())
                    m1[a]=b;
                if(m2.find(b)==m2.end())
                    m2[b]=a;
                if(m1[a]!=b || m2[b]!=a){
                    f=true;
                    break;
                }   
            }
            if(!f)
                ans.push_back(w[i]);
        }
        return ans;
    }
};