class Solution {
public:
    
    int solve(vector<int>& A, int K){
        unordered_map<int,int> m;
        int i=0;
        int ans=0;
        for(int j=0;j<A.size();j++){
            if (!m[A[j]]++)
                K--;
            while (K<0) {
                if (!--m[A[i]])
                    K++;
                i++;
            }
            ans+=j-i+1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return solve(A,K) - solve(A,K-1);
    }
};