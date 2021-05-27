class Solution {
public:
    // use string as stack
    string removeDuplicates(string s) {
        string st;
        for(int i=0;i<s.size();i++){
            if(st.empty())
                st.push_back(s[i]);
            else{
                if(st.back()==s[i])
                    st.pop_back();
                else
                    st.push_back(s[i]);
            }
        }
        return st;
    }
};