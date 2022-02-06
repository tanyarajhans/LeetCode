class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        map<int,int> m;
        while(j<n){
            if(m[nums[j]]+1<=2){
                m[nums[j]]++;
                nums[i]=nums[j];
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
    }
};