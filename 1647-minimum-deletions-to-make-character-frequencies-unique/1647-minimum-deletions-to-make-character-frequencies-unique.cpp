class Solution {
public:
    int minDeletions(string s) {
        map<int,vector<char>> m;
        int n=s.size();
        map<char,int> freq;
        for(auto ch: s){
            freq[ch]++;
        }
        for(auto it: freq){
            m[it.second].push_back(it.first);
        }
        int ans=0;
        map<int,vector<char>>::reverse_iterator it;
        for (it = m.rbegin(); it!= m.rend(); it++) {
            int v=it->second.size();
            if(v<2)
                continue;
            for(int j=0;j<v-1;j++){
                char c=it->second[j];
                int f=it->first;
                while(m.count(f) && f>0){
                    f--;
                    ans++;
                }
                m[f].push_back(c);
            }
        }
        return ans;
    }
};