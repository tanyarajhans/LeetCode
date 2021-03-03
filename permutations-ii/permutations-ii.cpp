class Solution {
public:
     bool visit[9];
     void backtrack(set<vector<int>> &t,vector<int> &ans, vector<int>& nums){
       if(ans.size()==nums.size()){
          t.insert(ans);
           return;
       }
       
      for(int i=0;i<nums.size();i++){
           if(visit[i] || (i>0 && nums[i] == nums[i-1] && visit[i-1] == false))
                continue;
               ans.push_back(nums[i]);
               visit[i]=true;
               backtrack(t, ans, nums);
               ans.pop_back();
               visit[i]=false;
           }
       
       
   }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      sort(nums.begin(),nums.end());
       set<vector<int>> t;
       vector<int> ans;
        vector<vector<int>> v;
       backtrack(t, ans, nums);
       for(auto it: t)
           v.push_back(it);
       return v; 
    }
};