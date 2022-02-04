class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        int s=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                s--;
            else
                s++;
            if(s==0){
                ans=max(ans, i+1);
            }
            else{
                if(m.find(s)!=m.end()){
                    ans=max(ans, i-m[s]);
                }
                else m[s]=i;
            }
        }
        return ans;
    }
};