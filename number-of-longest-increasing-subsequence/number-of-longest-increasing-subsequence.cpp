class Solution {
public:
   
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return n;
        vector<int> l(n,1);
        vector<int> c(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                
                if(l[j]>=l[i]){
                    l[i]=l[j]+1;
                    c[i]=c[j];
                }
                else if(l[j]+1==l[i]){
                    c[i]+=c[j];
                }
              }
            }
        }
        
        int maxl=0,ans=0;
        for(int i=0;i<n;i++)
            maxl=max(maxl,l[i]);
        for(int i=0;i<n;i++){
            if(l[i]==maxl)
            {
                ans+=c[i];
              
            }
        }
        return ans;
    }
};
