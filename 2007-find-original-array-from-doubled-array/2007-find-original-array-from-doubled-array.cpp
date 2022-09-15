class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        vector<int>ans;
        if(n%2==1)
            return ans;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[changed[i]]++;
        }
        for(auto i:m){
            if(m.find(2*(i.first))!=m.end()){
                if(i.first==0){
                    int val=i.second;
                    if(val%2==1)
                        return {};
                    for(int i=0;i<val/2;i++)ans.push_back(0);
                    m.erase(i.first);
                }
                else{
                    int a=i.second;
                    while(a){
                        ans.push_back(i.first);
                        m[i.first]--;
                        if(m[2*i.first]==0)return{};
                        m[2*i.first]--;
                        if(m[2*i.first]==0)m.erase(2*i.first);
                        if(m[i.first]==0)m.erase(i.first);
                        a--;
                    }
                }
            }
            else{
                return {};
            }
        }
        return ans;
    }
};