class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> mask(n);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                mask[i]|=(1<<(words[i][j]-'a'));
            }
            for(int j=0;j<i;j++){
                if((mask[i]&mask[j])==0) //no common chars
                    ans=max(ans, (int)(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};