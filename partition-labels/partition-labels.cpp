class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<int> l(26,0);
        int s=0,e=0;
        for(int i=0;i<S.size();i++)
            l[S[i]-'a']=i;
        for(int i=0;i<S.size();i++){
            e=max(e, l[S[i]-'a']);
            if(i==e){
                ans.push_back(i-s+1);
                s=i+1;
            }
        }
        return ans;
    }
};