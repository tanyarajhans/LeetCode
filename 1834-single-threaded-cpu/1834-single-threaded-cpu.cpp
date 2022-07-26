class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(v.begin(), v.end()); //sort on the basis of enqueue time
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> ans;
        int ind=0;
        long long time=v[0][0];
        while(ind<n && v[ind][0]==time){
            pq.push({v[ind][1], v[ind][2]});
            ind++;
        }
        while(!pq.empty()){
            time+=pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
            if(pq.empty() && ind<n && time<v[ind][0]){
                time=v[ind][0];
            }
            while(ind<n && time>=v[ind][0]){
                pq.push({v[ind][1], v[ind][2]}); //processing time, ind
                ind++;
            }
        }
        return ans;
    }
};