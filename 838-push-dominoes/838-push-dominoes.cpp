class Solution {
public:
    string pushDominoes(string s) {
        int n=s.size();
        int l[n];
        int r[n];
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
                f=max(f-1,0);
            else if(s[i]=='R')
                f=n;
            else
                f=0;
            l[i]=f;
        }
        f=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='.')
                f=max(f-1,0);
            else if(s[i]=='R')
                f=0;
            else
                f=n;
            r[i]=f;
        }
        // int preL[n];
        // int preR[n];
        // preL[0]=l[0];
        // preR[n-1]=r[n-1];
        // for(int i=1;i<n;i++){
        //     preL[i]=preL[i-1]+l[i];
        // }
        // for(int i=n-2;i>=0;i--){
        //     preR[i]=preR[i+1]+r[i];
        // }
        string ans;
        for(int i=0;i<n;i++){
            int x=l[i]-r[i];
            if(x==0)
                ans+=".";
            else if(x<0)
                ans+="L";
            else
                ans+="R";
        }
        return ans;
    }
};