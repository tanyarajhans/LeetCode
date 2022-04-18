class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int> incq;
        deque<int> decq;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            int x=nums[j];
            while(!incq.empty() && nums[incq.back()]>=x)
                incq.pop_back();
            while(!decq.empty() && nums[decq.back()]<=x)
                decq.pop_back();
            incq.push_back(j);
            decq.push_back(j);
            
            int mini=nums[incq.front()];
            int maxi=nums[decq.front()];
            
            if(maxi-mini<=limit){
                ans=max(ans, j-i+1);
            }
            else{
                i++;
                if(i>incq.front()){
                    incq.pop_front();
                }
                if(i>decq.front()){
                    decq.pop_front();
                }
            }
            j++;
        }
        return ans;
    }
};