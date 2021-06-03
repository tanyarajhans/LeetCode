class Solution {
public:
    vector<pair<int, int>> adj[102];
    map<int, int> dist;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(vector<int> v: times){
            adj[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=1;i<=n;i++){
            dist[i]=INT_MAX;
        }
        pq.push({0,k}); //distance, node
        dist[k]=0;
        while(!pq.empty()){
            int curr=pq.top().second;
            int currd=pq.top().first;
            pq.pop();
            for(pair<int, int> edge: adj[curr]){
                if(currd + edge.second < dist[edge.first]){
                    dist[edge.first] = currd + edge.second;
                    pq.push({dist[edge.first], edge.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            ans=max(ans, dist[i]);
        }
        return ans;
    }
};