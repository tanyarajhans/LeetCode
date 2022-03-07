class Solution {
public:
    vector<double> ans;
    unordered_map<int, int> m;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<k;i++){
            maxh.push(nums[i]);
        }
        for(int i=k/2;i>0;i--){
            minh.push(maxh.top());
            maxh.pop();
        }
        int i=k;
        while(i<n){
            if(k%2==0){
                ans.push_back(((double)maxh.top()+(double)minh.top())/2.0);
            }
            else{
                ans.push_back(maxh.top()*1.0);
            }
            int p=nums[i-k];
            int q=nums[i];
            int balance=0;
            i++;
            
            if(p<=maxh.top()){
                balance--;
                if(p==maxh.top()){
                    maxh.pop();
                }
                else{
                    m[p]++;
                }
            }
            else{
                balance++;
                if(p==minh.top()){
                    minh.pop();
                }
                else{
                    m[p]++;
                }
            }
            
            if(!maxh.empty() && q<=maxh.top()){
                balance++;
                maxh.push(q);
            }
            else{
                balance--;
                minh.push(q);
            }
            
            if(balance<0){
                maxh.push(minh.top());
                minh.pop();
            }
            else if(balance>0){
                minh.push(maxh.top());
                maxh.pop();
            }
            
            while(!maxh.empty() && m[maxh.top()]){
                m[maxh.top()]--;
                maxh.pop();
            }
            
            while(!minh.empty() && m[minh.top()]){
                m[minh.top()]--;
                minh.pop();
            }
        }
        if(k%2==0){
            ans.push_back(((double)maxh.top()+(double)minh.top())/2.0);
        }
        else{
            ans.push_back(maxh.top()*1.0);
        }
        return ans;
    }
};