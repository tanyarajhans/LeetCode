class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int n=w1.size();
        int m=w2.size();
        int i=0,j=0;
        int p=0,q=0;
        while(i<n && j<m){
            char c1=w1[i][p];
            char c2=w2[j][q];
            if(c1!=c2)
                return false;
            p++;
            q++;
            if(p==w1[i].size()){
                i++;
                p=0;
            }
            if(q==w2[j].size()){
                j++;
                q=0;
            }
        }
        if(i==n && j==m)
            return true;
        return false;
    }
};