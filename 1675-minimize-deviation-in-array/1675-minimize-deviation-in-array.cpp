class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        int maxi=0, mini=INT_MAX;
        for(auto &x : nums){
            if(x%2!=0)
                x*=2;
            maxi=max(maxi, x);
            mini=min(mini, x);
        }
        if(maxi==mini)
            return 0;
        int diff=maxi-mini;
        priority_queue<int> pq;
        for(auto &x : nums){
            pq.push(x);
        }
        while((pq.top())%2==0){
            int curr=pq.top();
            diff=min(diff, curr-mini);
            pq.pop();
            curr/=2;
            mini=min(mini, curr);
            pq.push(curr);
        }
        diff=min(diff, pq.top()-mini);
        return diff;
    }
};