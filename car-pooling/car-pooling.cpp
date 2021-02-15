class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        if(n==1)
            return trips[0][0]<=capacity;
        vector<int> m(1001);
        for(int i=0;i<n;i++){
            m[trips[i][1]]+=trips[i][0];;
            m[trips[i][2]]-=trips[i][0];
        }
        int maxc=0;
        for(int i=0;i<1001;i++){
            if(maxc+m[i]>capacity)
                return false;
            maxc=maxc+m[i];
        }
        return true;
    }
};