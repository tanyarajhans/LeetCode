class Solution {
public:
    
    double getMed(vector<int>a1, vector<int>a2, int n, int m)
    {
        int l = 0, h = n;
        int total=n+m;
        while(l<=m)
        {
            int i = (l + h) / 2;
            int j = (total + 1) / 2 - i;
​
            int min1 = (i == n)?INT_MAX:a1[i];
            int max1 = (i == 0)?INT_MIN:a1[i - 1];
​
            int min2 = (j == m)?INT_MAX:a2[j];
            int max2 = (j == 0)?INT_MIN:a2[j - 1];
​
            if(max1 <= min2 && max2 <= min1)
            {
                if((total) % 2 == 0)
                    return ((double)max(max1, max2) + min(min1, min2)) / 2;
                else
                    return (double)max(max1, max2);
            }
            else if(max1 > min2)
                h = i - 1;
            else 
                l = i + 1;
        }
        
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        if(n==0 && m==0)
            return 0;
        if(n==0)
        {
            if(m%2)
                return nums2[m/2];
            else
                return (double)(nums2[m/2-1]+nums2[m/2])/2;
        }
        
        if(m==0)
        {
            if(n%2)
                return nums1[n/2];
            else
                return (double)(nums1[n/2-1]+nums1[n/2])/2;
        }
        
        if(n<m)
