class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m)
            return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0;i<n;i++){
            v1[s1[i]-'a']++;
        }
        int i=0,j=0;
        while(j<m){
            if(j-i+1<=n){
                v2[s2[j]-'a']++;
                j++;
            }
            else{
                if(v1==v2)
                    return true;
                v2[s2[i]-'a']--;
                i++;
            }
        }
        if(v1==v2)
            return true;
        return false;
    }
};