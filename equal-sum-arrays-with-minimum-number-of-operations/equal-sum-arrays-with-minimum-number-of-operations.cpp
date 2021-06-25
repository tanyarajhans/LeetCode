class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int s1=0,s2=0;
        if(min(n1,n2) * 6 < max(n1, n2))
            return -1;
        for(int i=0;i<n1;i++)
            s1+=nums1[i];
        for(int i=0;i<n2;i++)
            s2+=nums2[i];
        if(s1<s2){
            swap(nums1, nums2); //nums1 zada sum wala chahiye
        }
        int diff=abs(s1-s2);
        map<int, int> m;
        for(int i=0;i<nums2.size();i++){
            m[6-nums2[i]]++;
        }
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]-1]++;
        }
        int c=0;
        map<int, int>::reverse_iterator it;
        for(it=m.rbegin(); it!=m.rend(); it++){
            int k=it->second;
            int ele=it->first;
            while(k-->0 && diff>0){
                diff-=ele;
                c++;
            }
            if(diff<=0)
                return c;
        }
        return -1;
    }
};