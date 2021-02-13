class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;
        for(char ch:s){
            m[ch]++;
        }
        for(auto i:m){
            pq.push({i.second, i.first});
        }
        string ans="";
        while(!pq.empty()){
            int c=pq.top().first;
            char ch=pq.top().second;
            while(c--)
                ans+=ch;
            pq.pop();
            
        }
        return ans;
    }
};