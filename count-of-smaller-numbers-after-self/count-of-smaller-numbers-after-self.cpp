class Solution {
public:
    int arr[100005];
    
    void merge(vector<pair<int, int> >&v, int l, int mid, int r){
        int i=l;
        int j=mid;
        int c=0;
        vector<pair<int,int>> temp(r-l+1);
        int k=0;
        while(i<=mid-1 && j<=r){
            if(v[i].first>v[j].first){
                c++;
                temp[k++]=v[j++];
            }
            else{
                arr[v[i].second]+=c;
                temp[k++]=v[i++];
            }
        }
        while(i<=mid-1)
        {
            arr[v[i].second]+=c; //add the number of smaller elements
            temp[k++]=v[i++]; 
        }
        //add the remaining second array elements if left any
        while(j<=r)
        {
            temp[k++]=v[j++];
        }
        //change the pairs to make it in sorted order 
        for(int i=0;i<k;i++)
        {
            v[l++]=temp[i];
        }
        
    }
    
    void mergeSort(vector<pair<int, int> >&v, int l, int r){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(v, l, mid);
            mergeSort(v, mid+1, r);
            
            merge(v, l, mid+1, r);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int> > v;
        int n=nums.size();
        for(int i=0;i<n;i++)
            v.push_back({nums[i], i});
        mergeSort(v, 0, n-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=arr[i];
        return ans;
    }
};