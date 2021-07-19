class Solution {
public:
    int minSubArrayLen(int k, vector<int>& a) {
        int n=a.size();
        int s=0;
        int ss=0;
        int ans=INT_MAX, l=0;
        int i=0,j=0;
        while(j<n){
            if(s<k)
                s+=a[j];
            if(s>=k){
                int l=j-i+1;
                ans=min(ans, l);
                s-=a[i];
                i++;
            }
            if(s<k)
                j++;
        }
        if(ans<INT_MAX)
            return ans;
        
        return 0;
    }
};