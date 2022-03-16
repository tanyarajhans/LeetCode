class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n=pushed.size();
        int j=0;
        for(int i=0;i<n;i++){
            s.push(pushed[i]);
            while(!s.empty() && popped[j]==s.top()){
                s.pop();
                j++;
            }
        }
        return j==n;
    }
};