class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)
            return false;
        map<int,int> m;
        for(auto i: nums)
            m[i]++;
        for(auto i: m){
            if(i.second){
                int x=i.second;
                for(int j=1;j<k;j++){
                    if(m[i.first+j]<x)
                        return false;
                    else
                        m[i.first+j]-=x;
                }
            }
        }
        return true;
    }
};