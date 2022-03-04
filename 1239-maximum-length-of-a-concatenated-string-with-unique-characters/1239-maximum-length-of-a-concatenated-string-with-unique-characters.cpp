class Solution {
public:
    int n;
    int ans=0;
    
    void backtrack(int ind, string curr, vector<string>& arr){
        if(ind==n){
            int v=curr.size();
            cout<<curr<<" ";
            ans=max(ans, v);
            return;
        }
        int v=arr[ind].size();
        unordered_map<char, int> m1,m2;
        for(auto &x: curr){
            m1[x]++;
        }
        bool f=true;
        for(auto &x: arr[ind]){
            if(m1.count(x) || m2.count(x))
            {
                f=false;
                break;
            }
            m2[x]++;
        }
        if(f){
            curr+=arr[ind];
            backtrack(ind+1, curr, arr);
            curr=curr.substr(0, curr.size()-v);
            backtrack(ind+1, curr, arr);
        }
        else{
            backtrack(ind+1, curr, arr);
        }
    }
    
    int maxLength(vector<string>& arr) {
        n=arr.size();
        string curr="";
        backtrack(0, curr, arr);
        return ans;
    }
};