class Solution {
public:
    
    bool isValid(vector<int>& a, int mid, int m, int k){
        int ans=0;
        int total=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]<=mid)
                total++;
            else{
                if(total>=k)
                    ans++;
                total=0;
            }
            if(total>=k){
                ans++;
                total=0;
            }
        }
        if(total>=k)
            ans++;
        return (ans>=m);
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=1;
        int n=bloomDay.size();
        if((long long)n<(long long)m*k)
            return -1;
        for(int i=0;i<n;i++)
            r=max(r, bloomDay[i]);
        while(l<r){
            long long mid=(long long)l+(r-l)/2;
            if(isValid(bloomDay, mid, m, k))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
