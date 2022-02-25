class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.size();
        int m=v2.size();
        vector<long> x1,x2;
        string s1="";
        for(int i=0;i<n;i++){
            if(v1[i]!='.')
                s1+=v1[i];
            else{
                x1.push_back(stol(s1));
                s1="";
            }
        }
        x1.push_back(stol(s1));
        s1="";
        for(int i=0;i<m;i++){
            if(v2[i]!='.')
                s1+=v2[i];
            else{
                x2.push_back(stol(s1));
                s1="";
            }
        }
        x2.push_back(stol(s1));
        int i=0;
        while(i<x1.size() && i<x2.size()){
            if(x1[i]<x2[i])
                return -1;
            else if(x1[i]>x2[i])
                return 1;
            i++;
        }
        while(i<x1.size()) {
            if(x1[i] != 0) {
                return 1;
            }
            i++;
        }
        while(i<x2.size()) {
            if(x2[i] != 0) {
                return -1;
            }
            i++;
        }
        return 0;
    }
};