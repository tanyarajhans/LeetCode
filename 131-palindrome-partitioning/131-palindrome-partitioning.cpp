class Solution {
public:
    vector<vector<string>> ans;
    int n;
    
    bool isPal(int i, int j, string &v){
        while(i<j){
            if(v[i]!=v[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int ind, vector<string> &temp, string &s){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isPal(ind, i, s)){
                string v=s.substr(ind,i-ind+1);
                temp.push_back(v);
                solve(i+1, temp, s);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        n=s.size();
        int ind=0;
        solve(ind, temp, s);
        return ans;
    }
};