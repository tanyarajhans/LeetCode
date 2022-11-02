class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> s;
        
        for(auto &x: bank)
            s.insert(x);
        
        if(s.find(end)==s.end())
            return -1;
        
        queue<string> q;
        q.push(start);
        unordered_set<string> vis;
        vis.insert(start);
        int ans=0;
        string st="ACGT";
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto curr=q.front();
                q.pop();
                if(curr==end)
                    return ans;
                auto x=curr;
                for(int i=0;i<curr.size();i++){
                    for(int j=0;j<st.size();j++){
                        curr[i]=st[j];
                        if(vis.find(curr)==vis.end() && s.find(curr)!=s.end() ){
                            q.push(curr);
                            vis.insert(curr);
                        }
                    }
                    curr=x;
                }
            }
            ans++;
        }
        return -1;
    }
};