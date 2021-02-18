class Solution {
    struct comp{
        bool operator()(pair<int,int> p1, pair<int,int> p2){
            return p1.first+p1.second < p2.first+p2.second;
        }
      };
public:
   vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                pq.push({nums1[i], nums2[j]});
                if(pq.size()>k)
                    pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};