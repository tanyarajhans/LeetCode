class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
       
        if(n==1 || nums[0]==0)
            return 0;
        
        int end=nums[0];
        int maxend=nums[0];
        int j=1;
        for(int i=1;i<n;i++){
            if(i==n-1)
                return j;
            maxend=max(maxend, i+nums[i]);
            if(i==end){
                j++;
                end=maxend;
            }
        }
        return j;
    }
};
