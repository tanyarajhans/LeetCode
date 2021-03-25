class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int i=0,n=s.size();
        string ans="";
        while(i<n){
            st.push(s[i]);
            if(st.top()==']'){
                st.pop();
                string s1="";
                while(!st.empty() && st.top()!='['){
                    s1+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(s1.begin(), s1.end());
                string num="";
                string v="";
                int times=0;
                while(!st.empty() && isdigit(st.top())){
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                times=stoi(num);
                for(int i=0;i<times;i++)
                    v+=s1;
                for(int i=0;i<v.size();i++)
                    st.push(v[i]);
            }
            i++;
        }
        while(!st.empty()){
                    ans+=st.top();
                    st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};