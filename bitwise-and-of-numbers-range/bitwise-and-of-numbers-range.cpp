class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            ans++;
        }
        return m<<=ans;
    }
};