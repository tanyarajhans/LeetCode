class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int pre[A.size()+1];
        for(int i=0;i<A.size();i++){
            pre[i+1]=pre[i]+A[i];
        }
        unordered_map<int,int> m;
        int ans=0;
        for(int i:pre){
            ans+=m[i];
            m[i+S]++;
        }
        return ans;
    }
};