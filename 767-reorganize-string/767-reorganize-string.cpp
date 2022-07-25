class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        map<char,int> m;
        for(auto x: s)
            m[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto it: m)
            pq.push({it.second, it.first});
        string ans;
        while(pq.size()>1){
            auto x1=pq.top();
            pq.pop();
            auto x2=pq.top();
            pq.pop();
            char c1=x1.second;
            char c2=x2.second;
            int n1=x1.first;
            int n2=x2.first;
            ans.push_back(c1);
            ans.push_back(c2);
            n1--;
            n2--;
            if(ans.back()==ans[ans.size()-2])
                return "";
            if(n1>0)
                pq.push({n1, c1});
            if(n2>0)
                pq.push({n2, c2});
        }
        while(!pq.empty()){
            auto x1=pq.top();
            pq.pop();
            char c1=x1.second;
            int n1=x1.first;
            if(n1>1)
                return "";
            else{
                if(ans.size()>0 && ans.back()==c1)
                    return "";
                ans.push_back(c1);
            }
        }
        return ans;
    }
};