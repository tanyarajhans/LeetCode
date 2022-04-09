class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> m;
        for(auto &x: nums){
            m[x]++;
        }
        for(auto &x: m){
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};