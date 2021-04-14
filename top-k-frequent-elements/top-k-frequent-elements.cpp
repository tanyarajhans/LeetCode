class Solution {
public:
    
   vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int>m;
       priority_queue<pair<int,int>> pq;
        
        for(int i: nums){
            m[i]++;
        }
        
        for(auto i : m){
            pq.push({-i.second, i.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();   
        }
        return ans;
    }
};