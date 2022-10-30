class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        int n=plantTime.size();
        for(int i=0;i<n;i++){
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int p=0;
        int g=0;
        int ans=0;
        for(auto &x: v){
            p+=x.second;
            g=p+x.first;
            ans=max(ans, g);
        }
        return ans;
    }
};