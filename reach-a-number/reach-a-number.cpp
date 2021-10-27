class Solution {
public:
    
    int reachNumber(int target) {
        target=abs(target);
        int sum=0;
        int steps=0;
        while(sum<target){
            steps++;
            sum+=steps;
        }
        if(sum==target) //if n*(n+1)/2==target
            return steps;
        int diff=sum-target;
        if(diff%2==0) //if difference is even between target and current position, it can be a reverse step somewhere
            return steps;
        else{
            if(steps%2==0) //last step even, diff is odd (target 9, current 10) - next step difference even, can be a reverse step somewhere now  
                return steps+1;
            return steps+2; //last step odd, diff is odd (target 12, current 15) - after 2 steps difference even, can do a reverse step somewhere now 
        }
        return -1;
    }   
};