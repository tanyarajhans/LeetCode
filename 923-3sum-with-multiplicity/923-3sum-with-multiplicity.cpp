class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long ans=0;
        unordered_map<long long, long long> m;
        long long mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                ans+=m[target-arr[i]-arr[j]];
            }
            m[arr[i]]++;
        }
        return ans%mod;
    }
};