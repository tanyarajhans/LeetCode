class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return n;
        int prev=nums[1]-nums[0];
        int c=0;
        if(prev==0)
            c=1;
        else
            c=2;
        for(int i=2;i<n;i++){
            int next=nums[i]-nums[i-1];
            if((next>0 && prev<=0) || (next<0 && prev>=0))
            {
                c++;
                prev=next;
            }
        }
        return c;
    }
};