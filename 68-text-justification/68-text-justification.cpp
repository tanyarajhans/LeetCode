class Solution {
public:
    string solve(string s, int maxWidth, bool last){
        if(s.size()==maxWidth)
            return s;
        int spaces=0;
        for(auto &x: s)
            if(x==' ')
                spaces++;
        
        int rem=maxWidth-s.size();
        
        if(spaces==0 || last == 1){ //left align last line or single word
            s.insert(s.length(), rem,' ');
            return s;
        }
        
        int k=rem/spaces;
        int extra=rem%spaces;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' &&  (k>0 || extra>0)){
                int noOfSpaces= k+((extra--) > 0 ? 1:0);
                s.insert(i,noOfSpaces,' ');
                i+=noOfSpaces; 
            }
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string> ans;
        int i=1;
        string s=words[0];
        while(i<n){
            if(s.size()+1+words[i].size()>maxWidth){
                s=solve(s, maxWidth, 0);
                ans.push_back(s);
                s=words[i];
            }
            else{
                s+=" "+words[i];
            }
            i++;
        }
        s=solve(s, maxWidth, 1); //last line
        ans.push_back(s);
        return ans;
    }
};