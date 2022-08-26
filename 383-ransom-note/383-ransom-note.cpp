class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26]={0},b[26]={0};
        for(int i=0; i<ransomNote.size();i++){
            a[ransomNote[i]-'a']++;
        }
        for(int i=0; i<magazine.size();i++){
            b[magazine[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(a[i]>b[i]){
                return false;
            }
        }
        return true;
    }
};