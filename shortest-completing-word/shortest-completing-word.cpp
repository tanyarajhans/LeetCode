class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> m(26);
        string ans="";
        int l=INT_MAX;
        for(int i=0;i<licensePlate.size();i++){
            if(licensePlate[i]>='a' && licensePlate[i]<='z')
                m[licensePlate[i]-'a']++;
            else if(licensePlate[i]>='A' && licensePlate[i]<='Z')
                m[tolower(licensePlate[i])-'a']++;
        }
        vector<int> n(26);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                n[words[i][j]-'a']++;
            }
            bool f=true;
            for(int i=0;i<26;i++){
                if(m[i]>n[i]){
                    f=false;
                    break;
                }
            }
            if(f==true){
                if(l>words[i].size()){
                   ans=words[i];
                   l=words[i].size(); 
                }
            }
            for(int i=0;i<26;i++)
                n[i]=0;
        }
        return ans;
    }
};