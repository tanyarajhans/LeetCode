class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int index=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l=max(0,index-k),h=min(n-1,index+k-1);
        vector<int> ans;
        while(h-l+1>k){
            if(x-arr[l]>arr[h]-x)
                l++;
            else
                h--;
        }
        for(int i=l;i<=h;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
