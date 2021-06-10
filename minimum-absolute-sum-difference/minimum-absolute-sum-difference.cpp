class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n1s(nums1.begin(), nums1.end());
	sort(n1s.begin(), n1s.end());

	int mod = 1e9+7;
	int max_reduction = 0; // maximum reduction of difference that can be achieved for any element.
	int total_diff = 0; // Total absolute sum difference
	for (int i = 0; i < nums1.size(); i++) {
		int curr_diff = abs(nums1[i]-nums2[i]);
		total_diff += curr_diff;
		total_diff %= mod;

		// Don't bother optimizing this element, if we already found a better
		// optimization for another element.
		if (curr_diff <= max_reduction) {
			continue;
		}

		// Find two numbers that are closest to nums2[i] in nums1 array.
		// See if replacing nums1[i] with either one of them results in smaller absolute
		// difference for ith element.
		auto it = lower_bound(n1s.begin(), n1s.end(), nums2[i]);
		int new_diff = curr_diff;
		if (it != n1s.end()) {
			new_diff = min(new_diff, abs(nums2[i] - *it));
		}
		if (it != n1s.begin()) {
			new_diff = min(new_diff, abs(nums2[i] - *prev(it)));
		}

		max_reduction = max(max_reduction, (curr_diff - new_diff));
	}

	total_diff = (total_diff - max_reduction + mod) % mod;

	return total_diff;
    }
};