class Solution {
public:
    int mod=(1e9 + 7);
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> eng;
        for (int i = 0; i < n; ++i)
            eng.push_back({efficiency[i], speed[i]});
        sort(rbegin(eng), rend(eng));
        long speedSum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto&[e, s] : eng) {
            speedSum += s;
            pq.push(s);
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            ans=max(ans, speedSum*e);
        }
        return ans%mod;
    }
};