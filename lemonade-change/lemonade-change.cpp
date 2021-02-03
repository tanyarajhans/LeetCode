class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        if(n==0)
            return false;
        int f=0,t=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
               f++;
            }
            else if(bills[i]==10){
                if(f==0)
                    return false;
                t++;
                f--;
            }
            else{
                if(t>0 && f>=1)
                {
                    t--;
                    f--;
                }
                else if(f>=3){
                    f-=3;
                }
                else
                    return false;
            }
        }
        return true;
        
    }
};