class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        map<int, int> m;
        int ans=0;
        for(auto x: nums)
            m[x]++;
        for(auto x: m){ // x is start of streak
            if(!m.count(x.first-1)){ 
                int curr=x.first;
                int maxsf=1;
                while(m.find(curr+1)!=m.end()){
                    curr++;
                    maxsf++;
                }
            ans=max(ans, maxsf);
            }
        }
        return ans;
    }
};