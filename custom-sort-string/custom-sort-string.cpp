class Solution {
public:
    string customSortString(string order, string str) {
       priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>> > pq;
        map<char, int> m;
        map<char, int> f;
        for(int i=0;i<str.size();i++){
            m[str[i]]=1;
            f[str[i]]++;
        }
        for(int i=0;i<order.size();i++){
            if(m[order[i]]==1){
                pq.push({i, order[i]});
                m[order[i]]=2;
            }
        }
        string ans;
        while(!pq.empty()){
            char c=pq.top().second;
            int sz=f[c];
            while(sz--)
                ans+=c;
            pq.pop();
        }
        for(auto it: f){
            if(m[it.first]==1){
                int sz=it.second;
                while(sz--)
                  ans+=it.first;
            }
        }
        return ans; 
    }
};