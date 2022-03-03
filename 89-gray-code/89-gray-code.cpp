class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        
        for (int i = 1; i <= n; i++) {
            int prevLength = result.size();
            int mask = 1 << (i - 1);
            for (int j = prevLength - 1; j >= 0; j--) {
                result.push_back(mask + result[j]);
            }
        }
        return result;
    }
};