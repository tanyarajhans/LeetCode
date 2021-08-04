class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        int maxsf=a[0], minsf=a[0], ans=a[0];
        for(int i=1;i<n;i++){
            int temp=maxsf;
            maxsf=max(a[i], max(maxsf*a[i], minsf*a[i]));
            minsf=min(a[i], min(temp*a[i], minsf*a[i]));
            ans=max(ans, maxsf);
        }
        return ans;
    }
};