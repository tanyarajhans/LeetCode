class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n=a.size();
        if(n==1)
            return a;
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        ans.push_back(a[0]);
        int st=a[0][0];
        int end=a[0][1];
        for(int i=1;i<n;i++){
            if(a[i][0]<=end){
                if(a[i][1]>end){
                    ans.pop_back();
                    end=a[i][1];
                    ans.push_back({st, end});
                }
            }
            else{
               st=a[i][0];
               ans.push_back(a[i]); 
            }
                 
            end=max(a[i][1], end);
        }
        return ans;
    }
};