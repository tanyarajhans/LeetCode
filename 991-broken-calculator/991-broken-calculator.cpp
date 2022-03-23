class Solution {
public:
    int brokenCalc(int start, int target) {
        if(start > target){ 
            return start - target; 
        }
        
        int num_ops = 0;
        int mult = 1;
        while(start < target){
            start *= 2;
            mult *= 2;
            num_ops++;
        }
        
        int diff = start - target;
        while(diff != 0){
            if(diff - mult < 0){
                mult /= 2;
            }
            else{
                diff -= mult;
                num_ops++;
            }
        }
        return num_ops;
    }
};