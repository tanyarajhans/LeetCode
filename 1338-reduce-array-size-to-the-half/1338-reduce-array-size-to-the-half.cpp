class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int> m;
        for(auto x: arr)
            m[x]++;
        priority_queue<int> pq;
        for(auto it: m)
            pq.push(it.second);
        int ans=0;
        int k=n;
        int c=0;
        while(!pq.empty()){
            int x=pq.top();
            c++;
            pq.pop();
            n-=x;
            if(n<=k/2)
                return c;
        }
        return c;
    }
};