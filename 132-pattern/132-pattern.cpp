class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int mini[n];
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
            mini[i]=min(mini[i-1], nums[i]);
        stack<int> st;
        for(int j=n-1;j>=0;j--){
            if(nums[j]>mini[j]){
                while(!st.empty() && st.top()<=mini[j]){
                    st.pop();
                }
                if(!st.empty() && st.top()<nums[j])
                    return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};