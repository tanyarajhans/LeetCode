class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a>0 && b>0){
            if(a>b){
                ans+="aab";
                a-=2;
                b--;
            }
            else if(b>a){
                ans+="bba";
                b-=2;
                a--;
            }
            else if(a==b){
                ans+="ab";
                a--;
                b--;
            }
        }
        while(a-->0)
            ans+="a";
        while(b-->0)
            ans+="b";
        return ans;
    }
};