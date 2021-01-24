class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n=houses.size();
        int m=heaters.size();
        vector<int> a(n, INT_MAX);
        
        for(int i=0,j=0;i<n && j<m;){
            if(houses[i]<=heaters[j]){
                a[i]=heaters[j]-houses[i];
                i++;
            }
            else
                j++;
        }
        
        for(int i=n-1,j=m-1;i>=0 && j>=0;){
            if(houses[i]>=heaters[j]){
                a[i]=min(houses[i]-heaters[j],a[i]);
                i--;
            }
            else
                j--;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,a[i]);
        return ans;
    }
};
