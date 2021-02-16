class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=n*2;
        int m=reservedSeats.size();
        unordered_map<int,vector<int>> mp;
        for(auto i:reservedSeats)
            mp[i[0]].push_back(i[1]);
        for(auto r: mp){
            bool l=false,h=false,mid=false;
            for(auto s: r.second){
                if(s>1&& s<6)
                    l=true;
                if(s>5&& s<10)
                    h=true;
                if(s>3&& s<8)
                    mid=true;
            }
            if(l)
                --ans;
            if(h)
                --ans;
            if(l && h && !mid)
                ++ans;
        }
        return ans;
    }
};