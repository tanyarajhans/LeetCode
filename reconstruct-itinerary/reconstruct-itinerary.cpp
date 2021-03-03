class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++)
            adj[tickets[i][0]].insert(tickets[i][1]);
        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            string s=st.top();
            if(adj[s].size()==0){
                ans.push_back(s);
                st.pop();
            }
            else{
                auto dst=adj[s].begin();
                st.push(*dst);
                adj[s].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};