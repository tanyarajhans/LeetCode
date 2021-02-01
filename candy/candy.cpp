class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1)
            return 1;
        vector<int> l(n,1);
        vector<int> r(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                l[i]=l[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                r[i]=r[i+1]+1;
        }
        int s=0;
        for(int i=0;i<n;i++)
            s+=max(l[i],r[i]);
        return s;
    }
};