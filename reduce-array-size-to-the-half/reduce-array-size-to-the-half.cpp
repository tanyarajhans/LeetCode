class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<pair<int,int>> v;
        unordered_map<int,int> m;
        int n=arr.size();
        for(auto i: arr)
            m[i]++;
        int total=0;
        for(auto i:m){
            v.push_back({i.second,i.first});
            total+=i.second;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int k=0;
        while(total>n/2){
            total-=v[k].first;
            k++;
        }
        return k;
    }
};