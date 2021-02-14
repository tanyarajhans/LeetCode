class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2, count = 0;
            for (int a : nums)
                count += (a - 1) / mid;
            if (count > maxOperations)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};