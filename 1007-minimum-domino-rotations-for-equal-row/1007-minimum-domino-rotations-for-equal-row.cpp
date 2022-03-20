class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        map<int, int> m1, m2, m3;
        for(int i=0;i<n;i++){
            m1[tops[i]]++;
            m2[bottoms[i]]++;
            if(tops[i]==bottoms[i])
                m3[bottoms[i]]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            if(m1[i]+m2[i]-m3[i]==n)
           ans=min(ans, n-max(m1[i],m2[i]));
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};