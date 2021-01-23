class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int ans=0;
        int l=0;
        int r=0;
        for(int i=0;i<arr.size();i++){
            r=max(r,arr[i]);   
        }
        int d=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            int s=0;
            for(int t: arr){
                s+=t>mid?mid:t;
            }
            if(abs(s-target)<d){
                d=abs(s-target);
                ans=mid;
            }
            if(abs(s-target)==d){
                ans=min(ans,mid);
            }
            if(s>target)
                r=mid-1;
            else if(s==target)
                r--;
            else
                l=mid+1;
        }
        return ans;
    }
};
