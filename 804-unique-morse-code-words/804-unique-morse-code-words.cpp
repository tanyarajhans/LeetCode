class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n=words.size();
        string v[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<words[i].size();j++){
                s+=(v[words[i][j]-'a']);
            }
            ans.insert(s);
        }
        return ans.size();
    }
};