class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        if(n==1)
            return 0;
        long long pre[n];
        long long suff[n];
        sort(beans.begin(), beans.end());
        suff[n-1]=beans[n-1];
        pre[0]=beans[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+beans[i];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+beans[i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(i==0)
                ans=min(ans, suff[i+1]-(long long)(n-1)*(long long)beans[i]);
            else if(i==n-1)
                ans=min(ans, pre[i-1]);
            else{
                long long t=(long long)pre[i-1]+(long long)suff[i+1];
                ans=min(ans, t-(long long)(n-i-1)*(long long)beans[i]);
            }
                
        }
        return ans;
    }
};