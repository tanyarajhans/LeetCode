class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int l[n];
        int r[n];
        int lind=0,rind=0;
        for(int i=0;i<n;i++){
            l[i]=-1;
            r[i]=-1;
        }
        l[0]=-1;
        for(int i=1;i<n;i++){
            if(s[i]=='|')
                l[i]=i;
            else
                l[i]=l[i-1];
        }
        r[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='|')
                r[i]=i;
            else
                r[i]=r[i+1];
        }
        int count[n];
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*')
                x++;
            count[i]=x;
        }
        vector<int> ans;
        for(auto x: queries){
            int ll=x[0];
            int rr=x[1];
            int prevInd=l[rr];
            int nextInd=r[ll];
            int c=0;
            if(prevInd>nextInd)
                c=count[prevInd]-count[nextInd];
            ans.push_back(c);
        }
        return ans;
    }
};