class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq; //height, endtime
        int i=0;
        while(i<n || !pq.empty()){
            int currx;
            if(pq.empty())
                currx=a[i][0];
            else
                currx=pq.top().second;
            if(i>=n || a[i][0]>currx){
                while(!pq.empty() && pq.top().second<=currx)
                    pq.pop();
            }
            else{
                currx=a[i][0];
                while(i<n && a[i][0]==currx){
                    pq.push({a[i][2], a[i][1]});
                    i++;
                }
            }
            int currh;
            if(pq.empty())
                currh=0;
            else
                currh=pq.top().first;
            if(ans.empty() || ans.back()[1]!=currh){
                ans.push_back({currx,currh});
            }
        }
        return ans;
    }
};