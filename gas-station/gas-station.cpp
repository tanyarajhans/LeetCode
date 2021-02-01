class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        bool f=true;
        int ans=0;
        int n=gas.size();
        if(n==1){
            if(gas[0]>=cost[0])
                return 0;
            else
                return -1;
        }
        for(int i=0;i<n;i++){
            if(gas[i]>=cost[i]){
               int j=i;
               int c=gas[j]-cost[j]+gas[(j+1)%n];
               j=(j+1)%n;
                while(j!=i){
                  if(c<cost[j])
                    break;
                  c=c-cost[j]+gas[(j+1)%n];
                  j=(j+1)%n;
                }
                if(j==i)
                  return i; 
            }
        }
        return -1;
    }
};