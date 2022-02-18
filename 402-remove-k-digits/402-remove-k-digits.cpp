class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        if(k==n)
            return "0";
        int i=0;
        while(i<n){
            while(!st.empty() && k>0 && num[i]<st.top()){
                k--;
                st.pop();
            }
            st.push(num[i]);
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        while(k>0 && ans.size()>0){
            ans.pop_back();
            k--;
        }
        while(ans.size()>0 && ans[0]=='0'){
            ans.erase(ans.begin());
        }
        if(ans.size()>0)
            return ans;
        return "0";
    }
};