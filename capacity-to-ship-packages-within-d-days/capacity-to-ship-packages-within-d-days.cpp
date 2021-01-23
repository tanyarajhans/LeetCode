class Solution {
public:
    
    bool isValid(vector<int>& weights, int D, int k){
        int n=weights.size();
        int ans=1,sum=0;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>k){
                ans++;
                sum=0;
            }
            sum+=weights[i];
        }
        return (ans<=D);
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int l=1;
        for(int i=0;i<weights.size();i++)
            l=max(l,weights[i]);
        int r=25000001;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(weights, D, mid))
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};
