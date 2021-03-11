class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int ans=0;
        if(n==1 || n==2)
            return true;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]!='1'){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
           for(int i=idx+1;i<n;i++){
            if(s[i]=='1')
                return false;
         } 
        }
        
        if(idx==-1 || idx==n-1)
            return true;
        return true;
    }
};