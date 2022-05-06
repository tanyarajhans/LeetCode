class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            int c=1;
            if(!st.empty()){
                if(st.top().first==s[i]){
                    c=st.top().second+1;
                }
            }
            st.push({s[i],c});
            if(st.top().second==k){
                int d=k;
                while(d--){
                    st.pop();
                }
                s.erase(i - k + 1, k);
                i-=k;
            }
        }
        return s;
    }
};