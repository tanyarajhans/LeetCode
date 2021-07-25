class Solution {
public:

int par[100005], size[100005];
unordered_map<int, int> m;

int find(int u){
    if(u == par[u])
        return u;
    
    else
        return par[u]=find(par[u]);
}

void combine (int u, int v){
    u = find(u);
    v = find(v);
    
    if(u == v)
        return;
    
    else
    {
        if(size[u] > size[v])
        {
            par[v] = u;
            size[u] += size[v];
        }
        
        else
        {
            par[u] = v;
            size[v] += size[u];
        }
    
    }
}
    
int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<100005;i++){
           par[i]=i;
           size[i]=1;
       }
       for(int i=0;i<n;i++){
           if(m.count(nums[i]))
               continue;
           if(m.count(nums[i]-1))
               combine(m[nums[i]-1], i);
           if(m.count(nums[i]+1))
               combine(m[nums[i]+1], i);
           m[nums[i]]=i;
       }
       int ans=0;
       for(int i=0;i<n;i++){
        ans=max(ans, size[i]);
       }
       return ans;
    }
};