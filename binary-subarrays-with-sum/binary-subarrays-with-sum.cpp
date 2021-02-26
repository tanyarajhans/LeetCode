class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int pre[A.size()+1];
        int ans=0,s=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<A.size();i++){
            s+=A[i];
            int k=s-S;
            ans+=m[k];
            m[s]++;
        }
        return ans;
    }
};