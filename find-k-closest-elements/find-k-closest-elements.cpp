class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0, r=n-1;
        int ind=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>x)
               r=mid-1;
            else{
                ind=mid;
                l=mid+1;
            }
        }
        cout<<ind;
        l=max(ind-k,0), r=min(ind+k,n-1);
        vector<int> ans;
        int c=0;
        while(r-l>=k){
            if(abs(arr[l]-x)<=abs(arr[r]-x)){
                r--;
            }
            else{
                l++;
            }
        }
        for(int i=l;i<=r;i++)
            ans.push_back(arr[i]);
        return ans;
    }
};