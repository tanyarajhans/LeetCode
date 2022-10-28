class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1)
                    v1.push_back({i,j});
                if(img2[i][j]==1)
                    v2.push_back({i,j});
            }
        }
        int ans=0;
        unordered_map<int,int> mp; //unoordered map doesnt have hash function for pair
        for(auto it1:v1){
            for(auto it2:v2){
                int a=it1.first-it2.first;
                int b=it1.second-it2.second;
                mp[100*a+b]++;
                ans=max(ans,mp[100*a+b]);
            }
        }
        return ans;
    }
};