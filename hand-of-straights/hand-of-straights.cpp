class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n=hand.size();
        if(n%W!=0)
            return false;
        map<int,int> m;
        for(auto i: hand)
            m[i]++;
        for(auto i: m){
            if(i.second){
                int x=i.second;
                for(int j=1;j<W;j++){
                    if(m[i.first+j]<x)
                        return false;
                    else
                        m[i.first+j]-=x;
                }
            }
        }
        return true;
    }
};
