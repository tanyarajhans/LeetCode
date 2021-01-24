class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        if(k==0)
        {
           for(int i=1;i<n;i++){
               if(pre[i]==0)
                   return true;
               
                if(i>1){
                   for(int j=0;j<=i-2;j++){
                    if((pre[i]-pre[j])==0)
                        return true;
                }
              } 
           }
            return false;
        }
        for(int i=1;i<n;i++)
        {
            if(pre[i]%k==0)
                   return true;
            if(i>1){
                for(int j=0;j<=i-2;j++){
                    if((pre[i]-pre[j])%k==0)
                        return true;
                }
            }
        }
        return false;
    }
};
