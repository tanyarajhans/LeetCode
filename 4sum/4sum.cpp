class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
       int n=a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        if(n<4)
            return ans;
        for(int i=0;i<n-3;i++){
            while(i>0 && a[i]==a[i-1])
                i++;
            for(int j=i+1;j<n-2;j++){
                while(j>i+1 && a[j]==a[j-1])
                    j++;
                long long sum=t-a[i]-a[j];
                int l=j+1, r=n-1;
                while(l<r){
                    int s1=a[l]+a[r];
                    if(s1>sum)
                        r--;
                    else if(s1<sum)
                        l++;
                    else{
                        ans.push_back({a[i], a[j], a[l], a[r]});
                        l++;
                        r--;
                        while(a[l]==a[l-1] && l<r)
                            l++;
                        while(a[r]==a[r+1] && l<r)
                            r--;
                    }
                }
            }
        }
        return ans;
    }
};