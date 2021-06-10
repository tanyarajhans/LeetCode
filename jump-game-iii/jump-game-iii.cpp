class Solution {
public:
    vector<int> adj[50005];
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        if(arr[start]==0)
            return true;
        bool vis[n];
        for(int i=0;i<n;i++)
        {
            adj[i].push_back(i+arr[i]);
            adj[i].push_back(i-arr[i]);
            vis[i]=false;
        }
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(arr[curr]==0)
                return true;
            if(curr+arr[curr]<n && !vis[curr+arr[curr]]){
                q.push(curr+arr[curr]);
                vis[curr+arr[curr]]=true;
            }
                
            if(curr-arr[curr]>=0 && !vis[curr-arr[curr]]){
                q.push(curr-arr[curr]);
                vis[curr-arr[curr]]=true;
            }
        }
        return false;
    }
};