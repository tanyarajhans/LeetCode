class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j;
        multiset<int> m;
        int n=nums.size();
        for (j=0; j<n; ++j) {
            m.insert(nums[j]);
            if (*m.rbegin() - *m.begin() > limit) // last and first element diff > limit
                m.erase(m.find(nums[i++]));
        }
        return j-i;
    }
};