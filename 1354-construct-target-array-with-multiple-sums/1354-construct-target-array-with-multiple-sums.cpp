class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum=0;
        int maxi=0;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            if(target[i]>target[maxi])
                maxi=i;
        }
        long long diff=sum-target[maxi];
        if(diff==1 || target[maxi]==1)
            return true;
        if(diff==0 || target[maxi]%diff==0 || target[maxi]<diff )
            return false;
        target[maxi]%=diff;
        return isPossible(target);
    }
};