class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool b1=true, b2=true;
        for(int i=0;i<s1.size();i++){
            if(s1[i]<s2[i])
                b1=false;
            if(s2[i]<s1[i])
                b2=false;
        }
        if(b1||b2)
            return true;
        return false;
    }
};