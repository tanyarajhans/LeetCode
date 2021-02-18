class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> l(n,n);
        vector<int> r(n,n);
        for(int i=0;i<n;i++){
            if(seats[i]==1)
                l[i]=0;
            else if(i>0)
                l[i]=l[i-1]+1;
        }
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1)
                r[i]=0;
            else if(i+1<n)
                r[i]=r[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]==0)
                ans=max(ans, min(l[i], r[i]));
        }
        return ans;
    }
};