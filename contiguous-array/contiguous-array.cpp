class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int s=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                s+=-1;
            else
                s+=1;
            if(s==0)
                l=i+1;
            if(m.find(s)!=m.end())
                l=max(i-m[s], l);
            else
                m[s]=i;
        }
        return l;
    }
};