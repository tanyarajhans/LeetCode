class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &it:nums)
            freq[it]++;
        for(auto &it:nums){
            if(freq[it]==0)
                continue;
            int fr=freq[it],count=0;
            while(freq[it]>=fr){
                fr=max(fr,freq[it]);
                freq[it]--;
                count++;
                it++;
            }
            if(count<3)
                return 0;
        }
        return 1;
    }
};