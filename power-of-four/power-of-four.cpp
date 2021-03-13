class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<32;i+=2){
            if(n==(1<<i))
                return true;
        }
        return false;
    }
};