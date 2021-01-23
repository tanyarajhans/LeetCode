class Solution {
public:
    
    bool isValid(vector<int>& piles, int H, int k){
        int n=piles.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int x=piles[i]/k;
            int y=piles[i]%k;
            if(y>0)
                x++;
            ans+=x;
        }
        return (ans<=H);
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int l=1;
        int r=1e9+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(piles, H, mid))
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};
