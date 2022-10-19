class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        string ans="";
        if(n==1)
            return res;
        while(n-1){
            for(int i=0;i<res.size();++i){
                int count=1;
                char c=res[i];
                while(i+1<res.size() && res[i]==res[i+1]){
                    count++;
                    i++;
                }
                ans+=to_string(count);
                ans+=c;
            }
            res=ans;
            ans="";
            n--;
        }
        return res;
    }
};