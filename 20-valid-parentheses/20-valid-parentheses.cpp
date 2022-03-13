class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        if(n%2!=0)
            return false;
        for(int i=0;i<n;i++){
           if(s[i]=='('  || s[i]=='{' || s[i]=='[') 
            st.push(s[i]);
            
            if(s[i]==')') {
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else
                    return false;
            }
               
            if(s[i]=='}') {
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else
                    return false;
            }
               
            if(s[i]==']') {
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else
                    return false;
            }
            
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};