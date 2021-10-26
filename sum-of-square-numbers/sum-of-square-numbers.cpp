class Solution {
public:
    
    bool bs(long long s, long long e, int n){
        if(s>e)
            return false;
        long long mid=s+(e-s)/2;
        if(mid*mid==n)
            return true;
        if(mid*mid>n)
            return bs(s,mid-1, n);
        return bs(mid+1, e, n);
    }
    
    bool judgeSquareSum(int c) {
        for(long long a=0;a*a<=c;a++){
            int b=c-a*a;
            if(bs(0, b, b))
                return true;
        }
        return false;
    }
};