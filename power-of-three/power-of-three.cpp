class Solution {
public:
    bool isPowerOfThree(int n) {
        int k=2;
        int r=0;
        if(n<1)
            return false;
        if(n==1)
            return true;
        while(n>1){
            r=n%3;
            if(r!=0)
                return false;
            n/=3;
        }
        return true;
    }
};