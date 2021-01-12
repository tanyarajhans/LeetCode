class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry=(a&b);
        int sum=a^b;
        if(carry==0)
            return sum;
        carry<<=1;
        return getSum(carry,sum);
    }
};
