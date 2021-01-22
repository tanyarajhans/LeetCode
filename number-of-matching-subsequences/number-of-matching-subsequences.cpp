class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        map<string,int> m;
        for(int i=0;i<words.size();i++)
            m[words[i]]++;
        int c=0;
        map<string,int>::iterator it;
        for(it=m.begin(); it!=m.end();it++){
            int j=0;
            string s=it->first;
            for(int l=0;l<S.size() && j<s.size();l++){
                if(s[j]==S[l])
                    j++;
            }
            if(j==s.size())
                c+=it->second;
            
        }
        return c;
    }
};
