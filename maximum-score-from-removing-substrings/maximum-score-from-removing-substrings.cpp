class Solution {
public:
    
    int solve(string &s, char a, char b){
        stack<char> st;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top()==a && s[i]==b){
                    st.pop();
                    ans++;
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string str;
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        s=str;
        return ans;
    }
    
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int xx,yy;
        if(x>y){
            xx=solve(s, 'a', 'b');
            yy=solve(s, 'b', 'a');
        }
        else{
            yy=solve(s, 'b', 'a');
            xx=solve(s, 'a', 'b');
        }
        return xx*x+yy*y;
    }
};