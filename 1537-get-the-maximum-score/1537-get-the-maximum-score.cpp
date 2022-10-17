class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,i=0,j=0, ans=0;
        int n=nums1.size(), m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j])
                sum1+=nums1[i++];
            else if(nums1[i]>nums2[j])
                sum2+=nums2[j++];
            else{
                ans+=max(sum1,sum2)+nums1[i]; 
                sum1=0; 
                sum2=0; 
                i++; 
                j++;
            }
        }
        if(i<n){
            for(;i<n;i++){
                sum1+=nums1[i];
            }
        }
        if(j<m){
            for(;j<m;j++){
                sum2+=nums2[j];
            }
        }
        ans=(ans+max(sum1,sum2))%1000000007;
        return ans;
    }
};