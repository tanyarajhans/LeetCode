class Solution {
public:
    long long int merge(vector<int>& nums, vector<int>& temp, int l, int mid, int r){
        int i=l,j=mid,k=l;
        long long int ans=0;
        while(i<mid)
        {
            while(j<=r && (2LL*nums[j])<nums[i])
                j++;
            ans+=j-mid;
            i++;
        }
        i=l;
        j=mid;
        while(i<mid && j<=r){
            if(nums[i]<=nums[j]){
                temp[k]=nums[i];
                k++;
                i++;
            }
            else{
                temp[k]=nums[j];
                k++;
                j++;
            }
        }
        while(i<mid){
            temp[k]=nums[i];
            k++;
            i++;
        }
        while(j<=r){
            temp[k]=nums[j];
            k++;
            j++;
        }
        for(int i=l;i<=r;i++)
            nums[i]=temp[i];
        return ans;
    }
    long long int mergeSort(vector<int>& nums, vector<int>& temp, int st, int end){
        if(st>=end)
            return 0;
        int mid=st+(end-st)/2;
        long long int ans=0;
        ans+=mergeSort(nums, temp, st, mid);
        ans+=mergeSort(nums, temp, mid+1, end);
        
        ans+=merge(nums, temp, st, mid+1, end);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        return mergeSort(nums, temp, 0, n-1);
    }
};