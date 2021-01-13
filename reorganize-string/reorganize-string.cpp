class Solution {
public:
    string reorganizeString(string S) {
        if(S.size()<=1)
            return S;
        
        unordered_map<char,int> m;
        
        for(char i : S){
            m[i]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        
        string ans="";
        
        while(pq.size()>1){
            pair<int,char> p1=pq.top(),p2;
            ans+=p1.second;
            pq.pop();
            p1.first--;
            
                p2=pq.top();
                ans+=p2.second;
                pq.pop();
                p2.first--;
            
            if(ans.back()==ans[ans.size()-2]){
                return "";
            }
            if(p1.first>0)
                pq.push(p1);
            if(p2.first>0)
                pq.push(p2);
        }
        if(!pq.empty()) {
            pair<int,char> p1= pq.top();
            pq.pop();
            if(p1.first > 1) {
                return "";
            } else {
                ans+=p1.second;
            }
        }
        return ans;
    }
};
