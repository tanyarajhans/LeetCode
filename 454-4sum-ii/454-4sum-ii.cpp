class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        // sort(nums3.begin(), nums3.end());
        // sort(nums4.begin(), nums4.end());
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];
                m[sum]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=nums3[i]+nums4[j];
                ans+=m[-sum];
            }
        }
        return ans;
    }
};