class Solution {
public:
    bool visit[9];
     void backtrack(set<vector<int>> &t, vector<int>& nums, int p){
       if(p==nums.size()){
          t.insert(nums);
           return;
       }
       
      for(int i=p;i<nums.size();i++){
               swap(nums[i],nums[p]);
               backtrack(t, nums, p+1);
               swap(nums[i],nums[p]);
           }
       
       
   }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      sort(nums.begin(),nums.end());
       set<vector<int>> t;
       vector<vector<int>> v;
       backtrack(t,nums, 0);
       for(auto it: t)
           v.push_back(it);
       return v; 
    }
};