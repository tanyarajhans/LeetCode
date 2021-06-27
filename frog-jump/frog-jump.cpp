class Solution {
public:
    int t[2001][2001];
    unordered_map<int, int> m;
    int n;
    
    bool solve(int value, int index, int k, vector<int> a){
        if(index==n-1)
            return true;
        
        if(t[index][k]!=-1)
            return false;
        
        int x=0,y=0,z=0;
        if(k-1>0 && m.count(value+k-1)>0)
            x=solve(value+k-1, m[value+k-1], k-1, a);
        
        if(m.count(value+k)>0)
            y=solve(value+k, m[value+k], k, a);
        
        if(m.count(value+k+1)>0)
            z=solve(value+k+1, m[value+k+1], k+1, a);
        
        return t[index][k]=(x|(y|z));
        
    }
    
    bool canCross(vector<int>& stones) {
        n=stones.size();
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++)
            m[stones[i]]=i;
        if(stones[1]==1 && solve(stones[1], 1, 1, stones)) // value, index, k
            return true;
        return false;
    }
};