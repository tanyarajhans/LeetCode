class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        int ans=0,x=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='(')
                x++;
            else {
                x--;
                if(S[i-1]=='(')
                    ans+=1<<x;
             }
        }
        return ans;
    }
};