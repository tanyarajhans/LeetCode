class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        int x=1<<k;
        set<string> st;
        while(j<n){
            if(j-i+1==k){
                st.insert(s.substr(i,k));
                i++;
            }
            j++;
        }
        int d=st.size();
        return (d==x);
    }
};