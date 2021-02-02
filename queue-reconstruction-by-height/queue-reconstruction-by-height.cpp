class Solution {
public:
    
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0]==b[0])
          return a[1]<b[1];
        return a[0]<b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> ans(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int c=people[i][1];
            for(int j=0;j<n;j++){
                if(ans[j][0]==-1 && c==0){
                    ans[j][0]=people[i][0];
                    ans[j][1]=people[i][1];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>=people[i][0])
                    c--;
            }
        }
        return ans;
    }
};