class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        map<int,int> m;
        int ans=0;
        for(int i=0;i<n;i++)
            m[answers[i]]++;
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            int x=it->first+1;
            int y=it->second;
            int t=y%x;
            if(t>0)
                ans+=y-t+x;
            else
                ans+=y;
        }
        return ans;
    }
};