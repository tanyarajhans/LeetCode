
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m1[n], m2[n];
        for(int i=0;i<n;i++){
            m1[nums1[i]]=i;
        }
        ordered_set s1, s2;
        for(int i=0;i<n;i++){
            int pos=m1[nums2[i]];
            m2[i]=s1.order_of_key(pos+1);
            s1.insert(pos);
        }
        s2.insert(m1[nums2[n-1]]);
        long long ans=0;
        for(int i=n-2;i>=0;i--){
            int pos=m1[nums2[i]];
            int v=(n-i-1)-s2.order_of_key(pos+1);
            ans+=(long long)(v)*(long long)(m2[i]);
            s2.insert(pos);
        }
        return ans;
    }
};