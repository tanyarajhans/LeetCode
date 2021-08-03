class Solution {
public:
    int kadane(vector<int>& a){
        int n=a.size();
        int maxsf=a[0], ans=a[0];
        for(int i=1;i<n;i++){
            maxsf=max(maxsf+a[i], a[i]);
            ans=max(ans, maxsf);
        }
        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& a) {
        int n=a.size();
        // now find maximum subarray sum with window size<=n but it would be too hard
        // find minimum subarray sum and subtract it from total sum
        // for finding min subarray sum, make all values -ve and find max subarray sum
        int s=0;
        int q=kadane(a);
        if(q<0)
            return q;
        for(int i=0;i<n;i++)
            s+=a[i];
        for(int i=0;i<n;i++)
            a[i]=-a[i];
        int p=kadane(a); //-ve wala 
        return max(q, s+p);
    }
};