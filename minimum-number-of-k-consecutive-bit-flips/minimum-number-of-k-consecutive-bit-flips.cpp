class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
       int res=0;
       queue<int> flips;
  for (auto i = 0; i < A.size(); ++i) {
    if (A[i] != (flips.size() % 2 ? 0 : 1)) {
      ++res;
      flips.push(i + K - 1);
    }
    if (!flips.empty() && flips.front() <= i) flips.pop();
  }
  return flips.empty() ? res : -1;
    }
};