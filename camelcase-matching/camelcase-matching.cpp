class Solution {
public:
    
    bool isValid(string queries, string pattern){
        int j=0;
        for(int i=0;i<queries.size();i++){
            if(j<pattern.size()){
                if(pattern[j]==queries[i]){
                    j++;
                }
                else{
                    if(queries[i]>='A' && queries[i]<='Z')
                        return false;
                }
            }
            else
                if(queries[i]>='A' && queries[i]<='Z')
                        return false;
            
        }
        return j==pattern.size();
    }
        
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(isValid(queries[i], pattern));
        }
        return ans;
    }
};