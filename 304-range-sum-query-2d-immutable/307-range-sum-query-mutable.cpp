#includ<iostream>
using namespace std;

class Numarray{
  vector<int>arr;
  int sum=0;
  //int n=nums.size();
NumArray(vector<int>& nums){
  
  for(int i=0;i<nums.size();i++)
  {
      sum+=nums[i];  
  }
  
}
  void update(int index,int val){
    
 sum += (val - arr[index]);
        arr[index] = val;
    
  }
 int sumRange(int left, int right) {
   
   int ans=0;
      ans = sum - accumulate(arr.begin(), arr.begin()+left, 0) - accumulate(arr.begin()+right+1, arr.end(), 0);
     rreturn ans;
   
 }
  
};

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

