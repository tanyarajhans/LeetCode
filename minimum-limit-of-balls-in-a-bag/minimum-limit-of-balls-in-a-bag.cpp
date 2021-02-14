class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2, count = 0;
            for (int a : nums){
                count += a/mid;
                if(a%mid)
                  count++;
            }
            if (count > nums.size() + maxOperations)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};