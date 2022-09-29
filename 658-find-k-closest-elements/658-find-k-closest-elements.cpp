class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n=a.size();
        int l=0, r=n-1-k;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(x-a[mid]<=a[mid+k]-x){
                r=mid-1;
            }
            else
                l=mid+1;
        }
        vector<int> ans;
        for(int i=l;i<l+k;i++)
            ans.push_back(a[i]);
        return ans;
    }
};