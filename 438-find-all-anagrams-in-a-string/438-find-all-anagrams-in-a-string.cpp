class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int d=p.size();
        int n=s.size();
        int i=0,j=0;
        map<char,int> m;
        for(auto &x:p)
            m[x]++;
        
        map<char, int> m1;
        while(j<n){
            if(j-i+1<=d){
                m1[s[j]]++;
                j++;
            }
            else{
                bool f=true;
                for(auto x: m){
                    if(m1.find(x.first)==m1.end()){
                        f=false;
                        break;
                    }
                    else{
                        if(m1[x.first]!=x.second){
                        f=false;
                        break;
                        }
                    }
                }
                if(f){
                    ans.push_back(i);
                }
                m1[s[i]]--;
                if(m1[s[i]]==0)
                    m1.erase(s[i]);
                i++;
            }
        }
        bool f=true;
        for(auto x: m){
            if(m1.find(x.first)==m1.end()){
                f=false;
                break;
            }
            else{
                if(m1[x.first]!=x.second){
                    f=false;
                    break;
                }
            }
        }
        if(f){
            ans.push_back(i);
        }
        return ans;
    }
};